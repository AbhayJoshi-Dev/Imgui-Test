#include<iostream>
#include<SDL.h>
#include<imgui.h>
#include<imgui_impl_sdl.h>
#include<imgui_impl_sdlrenderer.h>

int main(int, char**)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Imgui-Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return false;
    }

    //setup imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);


    bool running = true;
    bool openWindow = false;

    ImVec4 color = ImVec4(0.f, 0.f, 0.f, 1.f);

    while(running)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if(event.type == SDL_QUIT)
            {
                running = false;
            }

            if(event.type == SDL_WINDOWEVENT && event.window.type == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
            {
                running = false;
            }
        }

        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hello World!");
        ImGui::Text("Important Stuff...");
        if(ImGui::Button("Save"))
        {
            std::cout << "Saved!" << std::endl;
        }

        ImGui::Checkbox("Open Another Window", &openWindow);
        ImGui::ColorEdit3("Color", (float *)&color);

        //second window
        if(openWindow)
        {
            ImGui::Begin("New Window");
            ImGui::Text("Saving Work...");
            if(ImGui::Button("Close"))
                openWindow = false;
            
            ImGui::End();
        }

        ImGui::End();

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, (Uint8)(color.x * 255), (Uint8)(color.y * 255), (Uint8)(color.z * 255), (Uint8)(color.w * 255));
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);

    }

    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}