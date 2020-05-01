    #include "..\header\DirectionalLight.hpp"

void OpenGLRender3D::DirectionalLight::setUniformVariables(ShaderProgramHelper::Shader_Program& shader)
{
    if (eneabledId != -1)
    {
        shader.set_uniform_value(eneabledId, eneabled);
        shader.set_uniform_value(directionId, direction);
        shader.set_uniform_value(ambientColorId, ambientColor);
        shader.set_uniform_value(diffuseColorId, diffuseColor);
        shader.set_uniform_value(specularColorId, specularColor);
    }
    else
        throw std::exception("La luz introducida no es soportada por el shader");
}

void OpenGLRender3D::DirectionalLight::getUniformId(ShaderProgramHelper::Shader_Program& shader, std::string lightId)
{
    eneabledId = shader.get_uniform_id(std::string("directionalLight[" + lightId + "].eneabled").c_str());
    directionId = shader.get_uniform_id(std::string("directionalLight[" + lightId + "].direction").c_str());
    ambientColorId = shader.get_uniform_id(std::string("directionalLight[" +  lightId + "].ambient").c_str());
    diffuseColorId = shader.get_uniform_id(std::string("directionalLight[" +  lightId + "].diffuse").c_str());
    specularColorId = shader.get_uniform_id(std::string("directionalLight[" + lightId + "].specular").c_str());
}
