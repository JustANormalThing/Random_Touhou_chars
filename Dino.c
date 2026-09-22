#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define NUM_CHARACTERS 18

typedef struct {
    const char *name;
    const char *png;
} Character;

int main(void)
{

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    Character chars[NUM_CHARACTERS] = {
        {"Reimu Hakurei","Imgs/re.png"},
        {"Marisa Kirisame","Imgs/Ma.png"},
        {"Rumia","Imgs/Ru.png"},
        {"Daiyousei","Imgs/3pixels_char1.png"},
        {"Cirno", "Imgs/9.png"},
        {"Hong Melling","Imgs/Mel.png"},
        {"Koakuma","Imgs/SecondOne.png"},
        {"Patchouli Knowledge","Imgs/Book.png"},
        {"Sakuya Izayoi", "Imgs/Knife.png"},
        {"Remillia Scarlet","Imgs/Remi.png"},
        {"Flandre Scarlet","Imgs/TasyFoodName.png"},
        {"Letty Whiterock","Imgs/TasyFoodName.png"},
        {"Chen","Imgs/Cat.png"},
        {"Alice Margatroid","Imgs/Aris.png"},
        {"Lily White",          "Imgs/Happy.png"},
        {"Lunasa Prismriver","Imgs/Prism.png"},
        {"Merlin Prismriver","Img/Prism2.png"},
        {"Lyrica Prismriver","Img/Lyrica.png"}

    };

    srand((unsigned int)time(NULL));

    int index = rand() % NUM_CHARACTERS;

    printf("Selected character: %s\n", chars[index].name);
    printf("Loading image: %s\n", chars[index].png);


    SDL_Window *win = SDL_CreateWindow(
        "Touhou Character",
        800,
        800,
        0
    );

    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, NULL);

    if (ren == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());

        SDL_DestroyWindow(win);
        SDL_Quit();

        return 1;
    }

    SDL_Surface *surface = IMG_Load(chars[index].png);

    if (surface == NULL) {
        printf("IMG_Load Error: %s\n", SDL_GetError());

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();

        return 1;
    }


    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surface);

    SDL_DestroySurface(surface);

    if (tex == NULL) {
        printf(
            "SDL_CreateTextureFromSurface Error: %s\n",
            SDL_GetError()
        );

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();

        return 1;
    }


    int quit = 0;
    SDL_Event e;

    while (!quit) {

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = 1;
            }
        }


        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderClear(ren);


        SDL_RenderTexture(ren, tex, NULL, NULL);


        SDL_RenderPresent(ren);
    }


    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}
