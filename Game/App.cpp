#include <SDL3/SDL.h>
#include <glad/gl.h>

#include <string>
#include <thread>
#include <iostream>




#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"

float counter;

Window window("CMakeGameDev", 1000, 800);

Camera camera = Camera(glm::vec3(0, 0, 10));

Shader basic("Basic.shader");

Model monkey;

Texture metal;

void DrawGameObject(Model& model, glm::mat4 transform, glm::mat4 view, Shader& shader, Texture* texture)
{
    if (texture)
    {
        glActiveTexture(GL_TEXTURE0);
        texture->Use();
    }


    shader.Use();
    shader.SetMat4("model", transform);
    shader.SetMat4("view", view);

    model.Draw();
}

glm::mat4 CalculateTransform(glm::vec3 pos, glm::vec3 rot = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1))
{
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, pos);
    if (rot != glm::vec3(0.0, 0.0, 0.0))
        transform = glm::rotate(transform, counter * glm::radians(50.0f), rot);
    transform = glm::scale(transform, scale);
    return transform;
}


void Draw()
{
    while (window.GetRun())
    {
        window.Events();

        glClearColor(0.5, 0.2, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 view = camera.GetViewMatrix();


     
        DrawGameObject(monkey, CalculateTransform({ 0,0,-5 }), view, basic, &metal);

        
        window.ReSize();
        SDL_GL_SwapWindow(window.GetWindow());
        
    }
}


int main()
{
    
    monkey.LoadModel("monkey3.obj");


    metal.Load("metal.jpg");

    basic.Use();
    basic.SetInt("surface", 0);
    

    glEnable(GL_DEPTH_TEST);


    //const auto jRenderThread = std::jthread(Draw);
    Draw();
    

    

    


    SDL_DestroyWindow(window.GetWindow());
    SDL_Quit();
    

    return 0;
}