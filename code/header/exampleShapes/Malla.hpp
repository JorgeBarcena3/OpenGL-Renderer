
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                             *
 *  Started by Jorge Barcena on March of 2020                                  *
 *                                                                             *
 *  This is free software released into the public domain.                     *
 *                                                                             *
 *  j.barcenalumbreras@gmail.com                                               *
 *                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef MALLA_HEADER
#define MALLA_HEADER

#include <vector>
#include <string>
#include "BaseModel3D.hpp"

namespace OpenGLRender3D
{

    class Malla : public BaseModel3D
    {
    private:


        float width;
        float height;
        int vertex_count;     


    public:

        Malla(float width, float height, int vertex_count, Scene& scene, std::string path = "",  std::string tx_path = "../../assets/default/texture.tga");
        ~Malla();

        void setHeightCoordinates(std::vector< GLfloat >& coordinates, std::vector< GLfloat >& tx, std::string path);
        void createVertices(std::vector< GLfloat >& coordinates, std::vector< GLfloat >& normals , std::vector< GLfloat >& tx);
        void createIndices(std::vector< GLfloat >& coordinates);
        void createColors(std::vector< GLfloat >& colors, std::vector< GLfloat >& coodinates);

        void render() override;


        // Heredado v�a BaseShape
        virtual void update() override;

    };

}

#endif
