#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define NUM_CHARACTERS  47

typedef struct {
    const char *name;
    const char *png;
    const char *info;
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
        {"Letty Whiterock","Imgs/WinterOne.png"},
        {"Chen","Imgs/Cat.png"},
        {"Alice Margatroid","Imgs/Aris.png"},
        {"Lily White","Imgs/Happy.png"},
        {"Lunasa Prismriver","Imgs/Prism.png"},
        {"Merlin Prismriver","Imgs/Prism2.png"},
        {"Lyrica Prismriver","Imgs/Lyrica.png"},
        {"Youmu Konpaku","Imgs/SwordHappyShortOne.png"},
        {"Yuyuko Saigyouji","Imgs/Eat.png"},
        {"Ran Yakumo","Imgs/Fox.png"},
        {"Yukari Yakumo","Imgs/StopTrowingThem.png"},
        {"Suika Ibuki","Imgs/RealyShort.png"},
        {"Wriggle Nightbug","Imgs/Its_a_Bug.png"},
        {"Mystia Lorelei","Imgs/SheHasACookingGame.png"},
        {"Keine Kamishirasawa","Imgs/AlsoHasAFunnyGame.png"},
        {"Tewi Inaba","Imgs/Funny.png"},
        {"Reisen Udongein Inaba","Imgs/Moon_Rabbit.png"},
        {"Eirin Yagokoro","Imgs/ShadyDealer.png"},
        {"Kaguya Houraisan","Imgs/MyPrincess.png"},//30
        {"Aya Shameimaru","Imgs/CameraOne.png"}, 
        {"Medicine Melancholy","Imgs/Small_Princess.png"},
        {"Yuuka Kazami","Imgs/Flowers.png"},
        {"Komachi Onozuka","Imgs/HmmmLazy.png"},
        {"Eiki Shiki, Yamaxanadu","Imgs/SheBecameShort.png"},
        {"Shizuha Aki","Imgs/leafs.png"},
        {"Minoriko Aki","Imgs/Food.png"},
        {"Hina Kagiyama","Imgs/MyPrincess.png"},
        {"Nitori Kawashiro","Imgs/MyPrincess.png"},
        {"Momiji Inubashiri","Imgs/MyPrincess.png"},
        {"Sanae Kochiya","Imgs/MyPrincess.png"},
        {"Kanako Yasaka","Imgs/MyPrincess.png"},
        {"Suwako Moriya","Imgs/MyPrincess.png","Suwako Moriya is the original goddess of the Moriya Shrine that now officially belongs to Kanako Yasaka but in Suwako's words she handles most of the divine services while Kanako and the shrine maiden, Sanae Kochiya, handle the sales and the duties of gathering faith.Suwako first appeared as the Extra Stage boss of Mountain of Faith and also became a playable character, or possible opponent, in Touhou Hisoutensoku."},
        {"Iku Nagae","Imgs/MyPrincess.png"}, 
        {"Tenshi Hinanawi","Imgs/TheBestOne.png","Tenshi Hinanawi  is a celestial who is the Eldest Daughter  of the Hinanawi clan. She first appeared as the main antagonist and final possible opponent for most story scenarios in Scarlet Weather Rhapsody, as well as a playable character. She later became a playable character in the versus mode of Touhou Hisoutensoku and fully appeared again as a playable character, or possible opponent, in Antinomy of Common Flowers."},//44
        {"Tenshi Hinanawi","Imgs/ShesOneOFMyFavs_So.png","Tenshi Hinanawi  is a celestial who is the Eldest Daughter  of the Hinanawi clan. She first appeared as the main antagonist and final possible opponent for most story scenarios in Scarlet Weather Rhapsody, as well as a playable character. She later became a playable character in the versus mode of Touhou Hisoutensoku and fully appeared again as a playable character, or possible opponent, in Antinomy of Common Flowers."},
        {"Tenshi Hinanawi","Imgs/MoreTenshi.png","Tenshi Hinanawi  is a celestial who is the Eldest Daughter  of the Hinanawi clan. She first appeared as the main antagonist and final possible opponent for most story scenarios in Scarlet Weather Rhapsody, as well as a playable character. She later became a playable character in the versus mode of Touhou Hisoutensoku and fully appeared again as a playable character, or possible opponent, in Antinomy of Common Flowers."} //46

        
        

    };

    srand((unsigned int)time(NULL));

    int index = rand() % NUM_CHARACTERS;
    printf("Selected character: %s\n", chars[index].name);
    printf("Loading image: %s\n", chars[index].png);
    printf("Info about them: %s\n",chars[index].info);


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
