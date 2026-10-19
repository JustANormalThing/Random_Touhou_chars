## About project
This project generates a random touhou chars, with there png.

## Geting started
Linux was not tested.

Windows without mingw was not tested.

You need SDL3 and SDL_Img using mingw for this project, I dont know if other work for this.
But I think you can try not mingw version if you can and maybe it will work.

Here are the links for them:

https://github.com/libsdl-org/SDL_image/releases/tag/release-3.4.6

https://github.com/libsdl-org/SDL/releases

Latest version up to this date 22.09.26
## Compiling
You can just downlaod alredy compiled project.
Or compile your self from source.

To compile this project:
```
git clone https://github.com/JustANormalThing/Random_Touhou_chars.git
```


```
gcc Dino.c -o Dino.exe -I"C:\Users\Admin\Desktop\NEWTEST\SMALL_PROJECT\SDL3-3.4.16\x86_64-w64-mingw32\include" -I"C:\Users\Admin\Desktop\NEWTEST\SMALL_PROJECT\SDL3_image-3.4.6\x86_64-w64-mingw32\include" -L"C:\Users\Admin\Desktop\NEWTEST\SMALL_PROJECT\SDL3-3.4.16\x86_64-w64-mingw32\lib" -L"C:\Users\Admin\Desktop\NEWTEST\SMALL_PROJECT\SDL3_image-3.4.6\x86_64-w64-mingw32\lib" -lmingw32 -lSDL3 -lSDL3_image 
```
This shoud be in one line.

Also your change to your own path to project.

If this does not work, try using differnt sdl3 mingw version.

If code does not work, make a bug report to be fair it shoud work maybe, I hope.


## Credit
Touhu Project by Zun

Big credit for SDL for making this possible
https://github.com/libsdl-org/SDL
https://github.com/libsdl-org/SDL_image/tree/main

Made using Gcc compiler.
Using mingw.


Art by:
Touhou Lyrica and Merlin by Zun

Koakuma by hanahello

Daiyousei (Daiyōsei) - Touhou - Image by NIMA

Houraisan Kaguya (Kaguya Hōraisan) - Touhou -  by myuutsuu 

Ibuki Suika (Suika Ibuki) - Touhou - Image by campagne

