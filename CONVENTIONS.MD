## C Coding Style Conventions

Note : rules are meant to be broken, so those are to be seen as guidelines rather than set in stone rules.

Code element | Convention | Example
--- | :---: | ---
Defines | ALL_CAPS | `#define PLATFORM_DESKTOP`
Macros | ALL_CAPS | `#define MIN(a,b) (((a)<(b))?(a):(b))`
Private Variables | m_UpperCase | `int p_ScreenWidth = 0;`, `float p_TargetFrameTime = 0.016f;`
Public Variables | p_UpperCase | `int p_ScreenWidth = 0;`, `float p_TargetFrameTime = 0.016f;`
Local variables | lower_case | `Vector2 player_position = { 0 };`
Global variables | lower_case | `bool fullscreen = false;`
Constants | UpperCase | `const int MaxValue = 8;`
Pointers | MyType *pointer | `Texture2D *array = NULL;`
float values | always x.xf | `float gravity = 10.0f`
Operators | value1 * value2 | `int product = value * 6;`
Operators | value1 / value2 | `int division = value / 4;`
Operators | value1 + value2 | `int sum = value + 10;`
Operators | value1 - value2 | `int res = value - 5;`
Functions (outside of classes) | lower_case | `init_window()`, `load_image_from_memory()`
Functions (inside of classes) | lowerCase | `Foo::initWindow()`, `Foo::loadImageFromMemory()`
Functions params | lower_case | `screen_width`, `screen_height`
Ternary Operator | (condition) ? result1 : result2 | `printf("Value is 0: %s", (value == 0) ? "yes" : "no");`

Other conventions:
 - Indentation is made using tab characters set as 4 spaces
 - Variable declarations must be made at the start of the scope, if possible
 	- with the exception of const / static variables, variables must not be initialised on the same line they are declared
	- an empty line should separate the variable declarations and the body of the function
 - Functions should be kept at the minimal possible size and only do one thing
 	- While the actual good length is to the discretion of the one writting the code, an upper bound of 60 lines is enough for most cases
	- In the same idea, it is recommanded to avoid lines that are too long. An upper bound of 80 characters per line is enough for most cases (with tabs being 4 characters)
 - Variables outside of classes/ functions must be static and not usable in other C files
 - Trailing spaces are always avoided
 - Control flow statements are followed **by a space**
 - C keywords must be followed by a space
 - Variable / function declaration must be aligned with tabs
 	- Same goes for back-slashes for multilines macros
 - Getters / Setters must be declared and implemented in the class declaration
 - Multiline macros must be used to reduce boilerplate, not obfuscate code. if it execute several lines, it must not end with a ;
 - Comments must explain code decisions, not what the code do. Exception for multiline macros that can get really confusing sometime

Macro exemple :
```c
#define FOO 	\
	bar();		\
	alice();	\
	bob()
```

## Files and Directories Naming Conventions

  - Directories are named using `snake_case`: `resources/models`, `resources/fonts` and should be one word when possible
  - Files are named using `snake_case`: `main_title.png`, `cubicmap.png`, `sound.wav`

_NOTE: Spaces and special characters are always avoided in the files/dir naming!_

## Games/Examples Directories Organization Conventions

 - Resource files are organized by context and usage in the game. Loading requirements for data are also considered (grouping data when required).
 - Descriptive names are used for the files, just reading the name of the file it should be possible to know what is that file and where fits in the game.

```
resources/audio/fx/long_jump.wav
resources/audio/music/main_theme.ogg
resources/screens/logo/logo.png
resources/screens/title/title.png
resources/screens/gameplay/background.png
resources/characters/player.png
resources/characters/enemy_slime.png
resources/common/font_arial.ttf
resources/common/gui.png
```
_NOTE: Some resources require to be loaded all at once while other require to be loaded only at initialization (gui, font)._

