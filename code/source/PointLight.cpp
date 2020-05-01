#include "..\header\PointLight.hpp"

void OpenGLRender3D::PointLight::setUniformVariables(ShaderProgramHelper::Shader_Program& shader)
{
    if (eneabledId != -1)
    {
        shader.set_uniform_value(colorId, color);
        shader.set_uniform_value(intensityId, intensity);
        shader.set_uniform_value(positionId, position);
        shader.set_uniform_value(eneabledId, eneabled);
        shader.set_uniform_value(ambientId, ambient);
        shader.set_uniform_value(difusseId, diffuse);
        shader.set_uniform_value(specularId, specular);
    }
    else
        throw std::exception("La luz introducida no es soportada por el shader");
}

void OpenGLRender3D::PointLight::getUniformId(ShaderProgramHelper::Shader_Program& shader, std::string lightId)
{
    colorId = shader.get_uniform_id(std::string("pointLights[" + lightId + "].color").c_str());
    intensityId = shader.get_uniform_id(std::string("pointLights[" + lightId + "].intensity").c_str());
    eneabledId = shader.get_uniform_id(std::string("pointLights[" + lightId + "].eneabled").c_str());
    positionId = shader.get_uniform_id(std::string("pointLights[" +      lightId + "].position").c_str());
    ambientId = shader.get_uniform_id(std::string("pointLights[" +  lightId + "].ambient").c_str());
    difusseId = shader.get_uniform_id(std::string("pointLights[" +  lightId + "].diffuse").c_str());
    specularId = shader.get_uniform_id(std::string("pointLights[" + lightId + "].specular").c_str());
}
