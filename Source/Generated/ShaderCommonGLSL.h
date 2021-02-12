// This file was generated by GenerateShaderCommon.py

#define MAX_STATIC_VERTEX_COUNT (1048576)
#define MAX_DYNAMIC_VERTEX_COUNT (2097152)
#define MAX_VERTEX_COLLECTOR_INDEX_COUNT (4194304)
#define MAX_GEOMETRY_PRIMITIVE_COUNT_POW (18)
#define MAX_BOTTOM_LEVEL_GEOMETRIES_COUNT_POW (14)
#define MAX_GEOMETRY_PRIMITIVE_COUNT (1 << MAX_GEOMETRY_PRIMITIVE_COUNT_POW)
#define MAX_BOTTOM_LEVEL_GEOMETRIES_COUNT (1 << MAX_BOTTOM_LEVEL_GEOMETRIES_COUNT_POW)
#define MAX_TOP_LEVEL_INSTANCE_COUNT (32)
#define BINDING_VERTEX_BUFFER_STATIC (0)
#define BINDING_VERTEX_BUFFER_DYNAMIC (1)
#define BINDING_INDEX_BUFFER_STATIC (2)
#define BINDING_INDEX_BUFFER_DYNAMIC (3)
#define BINDING_GEOMETRY_INSTANCES_STATIC (4)
#define BINDING_GEOMETRY_INSTANCES_DYNAMIC (5)
#define BINDING_GLOBAL_UNIFORM (0)
#define BINDING_ACCELERATION_STRUCTURE (0)
#define BINDING_TEXTURES (0)
#define BINDING_BLUE_NOISE (0)
#define INSTANCE_CUSTOM_INDEX_FLAG_DYNAMIC (1 << 0)
#define INSTANCE_MASK_ALL (0xFF)
#define INSTANCE_MASK_HAS_SHADOWS (1)
#define PAYLOAD_INDEX_DEFAULT (0)
#define PAYLOAD_INDEX_SHADOW (1)
#define SBT_INDEX_RAYGEN_PRIMARY (0)
#define SBT_INDEX_RAYGEN_DIRECT (1)
#define SBT_INDEX_RAYGEN_INDIRECT (2)
#define SBT_INDEX_MISS_DEFAULT (0)
#define SBT_INDEX_MISS_SHADOW (1)
#define SBT_INDEX_HITGROUP_FULLY_OPAQUE (0)
#define SBT_INDEX_HITGROUP_ALPHA_TESTED (1)
#define SBT_INDEX_HITGROUP_BLEND_ADDITIVE (2)
#define SBT_INDEX_HITGROUP_BLEND_UNDER (3)
#define MATERIAL_ALBEDO_ALPHA_INDEX (0)
#define MATERIAL_NORMAL_METALLIC_INDEX (1)
#define MATERIAL_EMISSION_ROUGHNESS_INDEX (2)
#define MATERIAL_NO_TEXTURE (0)
#define BLUE_NOISE_TEXTURE_COUNT (64)
#define BLUE_NOISE_TEXTURE_SIZE (64)
#define BLUE_NOISE_TEXTURE_SIZE_POW (6)
#define COMPUTE_COMPOSE_WORKGROUP_SIZE_X (16)
#define COMPUTE_COMPOSE_WORKGROUP_SIZE_Y (16)

#define MAX_RAY_LENGTH (10000.0)

struct ShVertexBufferStatic
{
    float positions[3145728];
    float normals[3145728];
    float texCoords[2097152];
    float texCoordsLayer1[2097152];
    float texCoordsLayer2[2097152];
};

struct ShVertexBufferDynamic
{
    float positions[6291456];
    float normals[6291456];
    float texCoords[4194304];
};

struct ShTriangle
{
    mat3 positions;
    mat3 normals;
    mat3x2 layerTexCoord[3];
    uvec3 materials[3];
    vec4 geomColor;
    vec3 tangent;
    float geomRoughness;
    vec3 geomEmission;
    float geomMetallicity;
};

struct ShGlobalUniform
{
    mat4 view;
    mat4 invView;
    mat4 viewPrev;
    mat4 projection;
    mat4 invProjection;
    mat4 projectionPrev;
    uint positionsStride;
    uint normalsStride;
    uint texCoordsStride;
    float renderWidth;
    float renderHeight;
    uint frameId;
    uint _pad0;
    uint _pad1;
    int instanceGeomInfoOffset[128];
};

struct ShGeometryInstance
{
    mat4 model;
    uvec4 materials[3];
    vec4 color;
    uint baseVertexIndex;
    uint baseIndexIndex;
    uint primitiveCount;
    float defaultRoughness;
    float defaultMetallicity;
    float defaultEmission;
    uint __pad0;
    uint __pad1;
};

struct ShPayload
{
    vec4 color;
    vec2 baryCoords;
    uint instIdAndIndex;
    uint geomAndPrimIndex;
    float clsHitDistance;
    float maxTransparDistance;
};

struct ShPayloadShadow
{
    uint isShadowed;
};

struct ShHitInfo
{
    vec3 albedo;
    float metallic;
    vec3 normal;
    float roughness;
    vec3 normalGeom;
    float hitDistance;
    vec3 emission;
};

#ifdef DESC_SET_FRAMEBUFFERS

// framebuffers

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 0, rgba32f)
    uniform image2D framebufAlbedo;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 1, rgba32f)
    uniform image2D framebufNormal;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 2, rgba32f)
    uniform image2D framebufNormal_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 3, rgba32f)
    uniform image2D framebufNormalGeometry;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 4, rgba32f)
    uniform image2D framebufNormalGeometry_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 5, rgba8)
    uniform image2D framebufMetallicRoughness;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 6, rgba8)
    uniform image2D framebufMetallicRoughness_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 7, r32f)
    uniform image2D framebufDepth;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 8, r32f)
    uniform image2D framebufDepth_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 9, r32ui)
    uniform uimage2D framebufRandomSeed;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 10, r32ui)
    uniform uimage2D framebufRandomSeed_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 11, rgba32f)
    uniform image2D framebufLightDirectDiffuse;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 12, rgba32f)
    uniform image2D framebufLightDirectDiffuse_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 13, rgba32f)
    uniform image2D framebufLightSpecular;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 14, rgba32f)
    uniform image2D framebufLightSpecular_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 15, rgba32f)
    uniform image2D framebufLightIndirect;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 16, rgba32f)
    uniform image2D framebufLightIndirect_Prev;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 17, rgba32f)
    uniform image2D framebufSurfacePosition;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 18, rgba32f)
    uniform image2D framebufViewDirection;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 19, rgba32f)
    uniform image2D framebufFinal;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 20, rgba32f)
    uniform image2D framebufDebugBounceNormal;

// samplers

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 21)
    uniform sampler2D framebufAlbedo_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 22)
    uniform sampler2D framebufNormal_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 23)
    uniform sampler2D framebufNormal_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 24)
    uniform sampler2D framebufNormalGeometry_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 25)
    uniform sampler2D framebufNormalGeometry_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 26)
    uniform sampler2D framebufMetallicRoughness_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 27)
    uniform sampler2D framebufMetallicRoughness_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 28)
    uniform sampler2D framebufDepth_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 29)
    uniform sampler2D framebufDepth_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 30)
    uniform usampler2D framebufRandomSeed_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 31)
    uniform usampler2D framebufRandomSeed_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 32)
    uniform sampler2D framebufLightDirectDiffuse_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 33)
    uniform sampler2D framebufLightDirectDiffuse_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 34)
    uniform sampler2D framebufLightSpecular_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 35)
    uniform sampler2D framebufLightSpecular_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 36)
    uniform sampler2D framebufLightIndirect_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 37)
    uniform sampler2D framebufLightIndirect_Prev_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 38)
    uniform sampler2D framebufSurfacePosition_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 39)
    uniform sampler2D framebufViewDirection_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 40)
    uniform sampler2D framebufFinal_Sampler;

layout(
    set = DESC_SET_FRAMEBUFFERS, binding = 41)
    uniform sampler2D framebufDebugBounceNormal_Sampler;
#endif
