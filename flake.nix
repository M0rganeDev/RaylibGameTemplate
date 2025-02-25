{
  description = "Raylib flake";

  # Flake inputs
  inputs = {
    nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.2411.*.tar.gz";
  };

  # Flake outputs
  outputs = { nixpkgs, ... }:
    let
      # Systems supported
      allSystems = [
        "x86_64-linux" # 64-bit Intel/AMD Linux
        "aarch64-linux" # 64-bit ARM Linux
        "x86_64-darwin" # 64-bit Intel macOS
        "aarch64-darwin" # 64-bit ARM macOS
      ];

      forAllSystems = f: nixpkgs.lib.genAttrs allSystems (system: f {
        pkgs = import nixpkgs { inherit system; };
      });

    in
    {
      devShells = forAllSystems ({ pkgs }:
        let libs = with pkgs; [
            clang
			gcc
            libGL
            wayland
			raylib
			libcxx
            xorg.libXrandr
            xorg.libXinerama
            xorg.libXcursor
            xorg.libXi
            xorg.libX11
            xorg.libXext
            glfw-wayland
            readline70
          ];
        in
        {
          default = (
              pkgs.mkShell.override {
                stdenv = pkgs.clangStdenv;
              }
          ) rec {
            env.CC = "clang";
            LD_LIBRARY_PATH = "/run/opengl-driver/lib";
            LIBCLANG_PATH = "${pkgs.llvmPackages.libclang.lib}/lib";
            packages = with pkgs; [
              clang-tools
			  gcc
              clang
              libllvm
              gnumake
              cmake
              gdb
              valgrind
              pkg-config
              entr
              shellspec
            ];
            nativeBuildInputs = packages;
            buildInputs = libs;
			shellHook = ''
cat <<EOL > "./.clangd"
CompileFlags:
	Add:
		- "-I${pkgs.raylib}/include/"
		- "-I${pkgs.libcxx.dev}/include/c++/v1/"
		- "-I./includes"
		- "-I./third_party/imgui"
		- "-I./third_party/rlImGui"
EOL
			'';
          };
        }
      );
    };
}
