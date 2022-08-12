#include "Scene.h"
#include <iostream>
#include "World/Terrain/Chunk.h"
#include "Graphics/Textures/TextureBuffer.h"
#include <time.h>
#include <chrono>

Scene::Scene()
{
    /* Initialize the library */
    if (!glfwInit()) {

        std::cout << "failed to init!!!";
        return;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "Voxel Game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "failed to load window!!!";

        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW did not init correctly";
    }

    if (!window)
    {
        glfwTerminate();
        std::cout << "failed to load window!!!";

        return;
    }
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);

}

void Scene::Start()
{
    Chunk chunk;
    ObjectShader OS("Assets/Shaders/Terrain.frag", "Assets/Shaders/Terrain.vert");
    Camera cam(1920,1080,glm::vec3(0,0,0));
    TextureBuffer texture;

    texture.Load("Assets/Textures/grass.png");

    int InitialTime = 0, FinalTime = 0;
    int Frames = 0;
    FinalTime = time(NULL);
    InitialTime = FinalTime + 1;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        cam.Input(window);
        texture.Bind(0);
        OS.SetUniform1i(0, 0);
        chunk.Draw(cam, OS);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        Frames++;
        FinalTime = time(NULL);

        if (FinalTime - InitialTime > 0) {
            std::cout << "frames " << Frames << std::endl;
            Frames = 0;
            InitialTime = FinalTime + 1;
        }

    }

    glfwTerminate();
}
