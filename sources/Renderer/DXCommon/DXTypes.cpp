/*
 * DXTypes.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "DXTypes.h"
#include <stdexcept>
#include <string>


namespace LLGL
{

namespace DXTypes
{


[[noreturn]]
void MapFailed(const std::string& typeName, const std::string& dxTypeName)
{
    throw std::invalid_argument("failed to map '" + typeName + "' to '" + dxTypeName + "' parameter");
}

[[noreturn]]
void UnmapFailed(const std::string& typeName, const std::string& dxTypeName)
{
    throw std::invalid_argument("failed to unmap '" + typeName + "' from '" + dxTypeName + "' parameter");
}

DXGI_FORMAT Map(const VertexAttribute& attrib)
{
    switch (attrib.dataType)
    {
        case DataType::Int8:
            if (attrib.conversion)
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R8_SNORM;
                    case 2: return DXGI_FORMAT_R8G8_SNORM;
                    case 4: return DXGI_FORMAT_R8G8B8A8_SNORM;
                }
            }
            else
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R8_SINT;
                    case 2: return DXGI_FORMAT_R8G8_SINT;
                    case 4: return DXGI_FORMAT_R8G8B8A8_SINT;
                }
            }
            break;
        
        case DataType::UInt8:
            if (attrib.conversion)
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R8_UNORM;
                    case 2: return DXGI_FORMAT_R8G8_UNORM;
                    case 4: return DXGI_FORMAT_R8G8B8A8_UNORM;
                }
            }
            else
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R8_UINT;
                    case 2: return DXGI_FORMAT_R8G8_UINT;
                    case 4: return DXGI_FORMAT_R8G8B8A8_UINT;
                }
            }
            break;
        
        case DataType::Int16:
            if (attrib.conversion)
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R16_SNORM;
                    case 2: return DXGI_FORMAT_R16G16_SNORM;
                    case 4: return DXGI_FORMAT_R16G16B16A16_SNORM;
                }
            }
            else
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R16_SINT;
                    case 2: return DXGI_FORMAT_R16G16_SINT;
                    case 4: return DXGI_FORMAT_R16G16B16A16_SINT;
                }
            }
            break;
        
        case DataType::UInt16:
            if (attrib.conversion)
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R16_UNORM;
                    case 2: return DXGI_FORMAT_R16G16_UNORM;
                    case 4: return DXGI_FORMAT_R16G16B16A16_UNORM;
                }
            }
            else
            {
                switch (attrib.components)
                {
                    case 1: return DXGI_FORMAT_R16_UINT;
                    case 2: return DXGI_FORMAT_R16G16_UINT;
                    case 4: return DXGI_FORMAT_R16G16B16A16_UINT;
                }
            }
            break;
        
        case DataType::Int32:
            switch (attrib.components)
            {
                case 1: return DXGI_FORMAT_R32_SINT;
                case 2: return DXGI_FORMAT_R32G32_SINT;
                case 3: return DXGI_FORMAT_R32G32B32_SINT;
                case 4: return DXGI_FORMAT_R32G32B32A32_SINT;
            }
            break;

        case DataType::UInt32:
            switch (attrib.components)
            {
                case 1: return DXGI_FORMAT_R32_UINT;
                case 2: return DXGI_FORMAT_R32G32_UINT;
                case 3: return DXGI_FORMAT_R32G32B32_UINT;
                case 4: return DXGI_FORMAT_R32G32B32A32_UINT;
            }
            break;

        case DataType::Float:
            switch (attrib.components)
            {
                case 1: return DXGI_FORMAT_R32_FLOAT;
                case 2: return DXGI_FORMAT_R32G32_FLOAT;
                case 3: return DXGI_FORMAT_R32G32B32_FLOAT;
                case 4: return DXGI_FORMAT_R32G32B32A32_FLOAT;
            }
            break;
    }
    MapFailed("VertexAttribute", "DXGI_FORMAT");
}

DXGI_FORMAT Map(const DataType dataType)
{
    switch (dataType)
    {
        case DataType::Int8:    return DXGI_FORMAT_R8_SINT;
        case DataType::UInt8:   return DXGI_FORMAT_R8_UINT;
        case DataType::Int16:   return DXGI_FORMAT_R16_SINT;
        case DataType::UInt16:  return DXGI_FORMAT_R16_UINT;
        case DataType::Int32:   return DXGI_FORMAT_R32_SINT;
        case DataType::UInt32:  return DXGI_FORMAT_R32_UINT;
        case DataType::Float:   return DXGI_FORMAT_R32_FLOAT;
        case DataType::Double:  break;
    }
    MapFailed("DataType", "DXGI_FORMAT");
}

DXGI_FORMAT Map(const TextureFormat textureFormat)
{
    switch (textureFormat)
    {
        /* --- Base internal formats --- */
        case TextureFormat::DepthComponent: return DXGI_FORMAT_D32_FLOAT;
        case TextureFormat::DepthStencil:   return DXGI_FORMAT_D24_UNORM_S8_UINT;
        case TextureFormat::R:              return DXGI_FORMAT_R8_UNORM;
        case TextureFormat::RG:             return DXGI_FORMAT_R8G8_UNORM;
        case TextureFormat::RGB:            break;
        case TextureFormat::RGBA:           return DXGI_FORMAT_R8G8B8A8_UNORM;

        /* --- Sized internal formats --- */
        case TextureFormat::R8:             return DXGI_FORMAT_R8_UNORM;
        case TextureFormat::R8Sgn:          return DXGI_FORMAT_R8_SNORM;

        case TextureFormat::R16:            return DXGI_FORMAT_R16_UNORM;
        case TextureFormat::R16Sgn:         return DXGI_FORMAT_R16_SNORM;
        case TextureFormat::R16Float:       return DXGI_FORMAT_R16_FLOAT;

        case TextureFormat::R32UInt:        return DXGI_FORMAT_R32_UINT;
        case TextureFormat::R32SInt:        return DXGI_FORMAT_R32_SINT;
        case TextureFormat::R32Float:       return DXGI_FORMAT_R32_FLOAT;

        case TextureFormat::RG8:            return DXGI_FORMAT_R8G8_UNORM;
        case TextureFormat::RG8Sgn:         return DXGI_FORMAT_R8G8_SNORM;

        case TextureFormat::RG16:           return DXGI_FORMAT_R16G16_UNORM;
        case TextureFormat::RG16Sgn:        return DXGI_FORMAT_R16G16_SNORM;
        case TextureFormat::RG16Float:      return DXGI_FORMAT_R16G16_FLOAT;

        case TextureFormat::RG32UInt:       return DXGI_FORMAT_R32G32_UINT;
        case TextureFormat::RG32SInt:       return DXGI_FORMAT_R32G32_SINT;
        case TextureFormat::RG32Float:      return DXGI_FORMAT_R32G32_FLOAT;

        case TextureFormat::RGB8:           break;
        case TextureFormat::RGB8Sgn:        break;

        case TextureFormat::RGB16:          break;
        case TextureFormat::RGB16Sgn:       break;
        case TextureFormat::RGB16Float:     break;

        case TextureFormat::RGB32UInt:      return DXGI_FORMAT_R32G32B32_UINT;
        case TextureFormat::RGB32SInt:      return DXGI_FORMAT_R32G32B32_SINT;
        case TextureFormat::RGB32Float:     return DXGI_FORMAT_R32G32B32_FLOAT;

        case TextureFormat::RGBA8:          return DXGI_FORMAT_R8G8B8A8_UNORM;
        case TextureFormat::RGBA8Sgn:       return DXGI_FORMAT_R8G8B8A8_SNORM;

        case TextureFormat::RGBA16:         return DXGI_FORMAT_R16G16B16A16_UNORM;
        case TextureFormat::RGBA16Sgn:      return DXGI_FORMAT_R16G16B16A16_SNORM;
        case TextureFormat::RGBA16Float:    return DXGI_FORMAT_R16G16B16A16_FLOAT;

        case TextureFormat::RGBA32UInt:     return DXGI_FORMAT_R32G32B32A32_UINT;
        case TextureFormat::RGBA32SInt:     return DXGI_FORMAT_R32G32B32A32_SINT;
        case TextureFormat::RGBA32Float:    return DXGI_FORMAT_R32G32B32A32_FLOAT;

        /* --- Compressed formats --- */
        case TextureFormat::RGB_DXT1:       return DXGI_FORMAT_BC1_UNORM;
        case TextureFormat::RGBA_DXT1:      return DXGI_FORMAT_BC1_UNORM;
        case TextureFormat::RGBA_DXT3:      return DXGI_FORMAT_BC2_UNORM;
        case TextureFormat::RGBA_DXT5:      return DXGI_FORMAT_BC3_UNORM;
    }
    MapFailed("TextureFormat", "DXGI_FORMAT");
}

D3D_PRIMITIVE_TOPOLOGY Map(const PrimitiveTopology topology)
{
    switch (topology)
    {
        case PrimitiveTopology::PointList:              return D3D_PRIMITIVE_TOPOLOGY_POINTLIST;
        case PrimitiveTopology::LineList:               return D3D_PRIMITIVE_TOPOLOGY_LINELIST;
        case PrimitiveTopology::LineStrip:              return D3D_PRIMITIVE_TOPOLOGY_LINESTRIP;
        case PrimitiveTopology::LineLoop:               break;
        case PrimitiveTopology::LineListAdjacency:      return D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ;
        case PrimitiveTopology::LineStripAdjacency:     return D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ;
        case PrimitiveTopology::TriangleList:           return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        case PrimitiveTopology::TriangleStrip:          return D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
        case PrimitiveTopology::TriangleFan:            break;
        case PrimitiveTopology::TriangleListAdjacency:  return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ;
        case PrimitiveTopology::TriangleStripAdjacency: return D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ;
        case PrimitiveTopology::Patches1:               return D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches2:               return D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches3:               return D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches4:               return D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches5:               return D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches6:               return D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches7:               return D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches8:               return D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches9:               return D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches10:              return D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches11:              return D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches12:              return D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches13:              return D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches14:              return D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches15:              return D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches16:              return D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches17:              return D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches18:              return D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches19:              return D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches20:              return D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches21:              return D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches22:              return D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches23:              return D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches24:              return D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches25:              return D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches26:              return D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches27:              return D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches28:              return D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches29:              return D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches30:              return D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches31:              return D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST;
        case PrimitiveTopology::Patches32:              return D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST;
    }
    MapFailed("PrimitiveTopology", "D3D_PRIMITIVE_TOPOLOGY");
}


} // /namespace DXTypes

} // /namespace LLGL



// ================================================================================
