
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                             *
 *  Started by �ngel on april of 2014                                          *
 *                                                                             *
 *  This is free software released into the public domain.                     *
 *                                                                             *
 *  angel.rodriguez@esne.edu                                                   *
 *                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef POSTPROCESSINGPROGRAM_HEADER
#define POSTPROCESSINGPROGRAM_HEADER

#include "Shader_Program.hpp"


namespace OpenGLRender3D
{

    using namespace ShaderProgramHelper;
    class Scene;

    class PostprocessingProgram
    {

    public:

        Scene * scene;

    private:
        
        GLuint vbo_ids[2];      // Ids de los VBOs que se usan

        GLuint vao_id;          // Id del VAO del programa de postproceso    

        GLuint triangle_vbo0;

        GLuint triangle_vbo1;


        GLuint frameBuffer_id;

        GLuint textureColorBuffer_id;

        GLuint depthRenderBuffer_id;

        ShaderProgramHelper::Shader_Program shaderProgram;


    public:

        PostprocessingProgram() = delete;

        PostprocessingProgram(Scene& _scene);

        ~PostprocessingProgram();

        void activeCurrentFrameBuffer();

        void render();

    private:

        void createScreenCoordinatesVAO();

        void createEffectFrameBuffer();

    };

}

#endif
