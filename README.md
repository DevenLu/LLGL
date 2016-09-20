Low Level Graphics Library (LLGL)
=================================

License
-------

[3-Clause BSD License](https://github.com/LukasBanana/LLGL/blob/master/LICENSE.txt)


Documentation
-------------

- [Getting Started with LLGL](https://github.com/LukasBanana/LLGL/blob/master/docu/GettingStarted/Getting%20Started%20with%20LLGL.pdf) (PDF)
- [LLGL Reference Manual](https://github.com/LukasBanana/LLGL/blob/master/docu/refman.pdf) (PDF)


Progress
--------

- **Version**: 1.00 Alpha
- **OpenGL Renderer**: ~70% done
- **Direct3D 12 Renderer**: ~5% done
- **Direct3D 11 Renderer**: ~5% done
- **Vulkan Renderer**: not started yet


Thin Abstraction Layer
----------------------

```cpp
// Interface:
RenderContext::DrawIndexed(unsigned int numVertices, unsigned int firstIndex);

// OpenGL Implementation:
void GLRenderContext::DrawIndexed(unsigned int numVertices, unsigned int firstIndex)
{
	glDrawElements(
		renderState_.drawMode,
		static_cast<GLsizei>(numVertices),
		renderState_.indexBufferDataType,
		(reinterpret_cast<const GLvoid*>(firstIndex * renderState_.indexBufferStride))
	);
}

// Direct3D 11 Implementation
void D3D11RenderContext::DrawIndexed(unsigned int numVertices, unsigned int firstIndex)
{
	context_->DrawIndexed(numVertices, firstIndex, 0);
}

// Direct3D 12 Implementation
void D3D12RenderContext::DrawIndexed(unsigned int numVertices, unsigned int firstIndex)
{
	commandList_->DrawIndexedInstanced(numVertices, 1, firstIndex, 0, 0);
}

// Vulkan Implementation
void VKRenderContext::DrawIndexed(unsigned int numVertices, unsigned int firstIndex)
{
	vkCmdDrawIndexed(commandBuffer_, numVertices, 1, firstIndex, 0, 0);
}
```


