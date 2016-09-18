/*
 * DbgShaderProgram.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_DBG_SHADER_PROGRAM_H__
#define __LLGL_DBG_SHADER_PROGRAM_H__


#include <LLGL/ShaderProgram.h>
#include <LLGL/RenderingDebugger.h>


namespace LLGL
{


class DbgShaderProgram : public ShaderProgram
{

    public:

        DbgShaderProgram(ShaderProgram& instance, RenderingDebugger* debugger);

        void AttachShader(Shader& shader) override;

        bool LinkShaders() override;

        std::string QueryInfoLog() override;
        std::vector<VertexAttribute> QueryVertexAttributes() const override;
        std::vector<ConstantBufferDescriptor> QueryConstantBuffers() const override;
        std::vector<StorageBufferDescriptor> QueryStorageBuffers() const override;
        std::vector<UniformDescriptor> QueryUniforms() const override;

        void BindVertexAttributes(const std::vector<VertexAttribute>& vertexAttribs) override;
        void BindConstantBuffer(const std::string& name, unsigned int bindingIndex) override;
        void BindStorageBuffer(const std::string& name, unsigned int bindingIndex) override;

        ShaderUniform* LockShaderUniform() override;
        void UnlockShaderUniform() override;

        ShaderProgram& instance;

    private:

        RenderingDebugger*  debugger_   = nullptr;
        bool                linked_     = false;

};


} // /namespace LLGL


#endif



// ================================================================================
