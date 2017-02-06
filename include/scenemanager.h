/*
    CIrrlicht - C Bindings for Irrlicht Engine

    Copyright (C) 2014- Danyal Zia (catofdanyal@yahoo.com)

    This software is provided 'as-is', without any express or
    implied warranty. In no event will the authors be held
    liable for any damages arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute
    it freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented;
       you must not claim that you wrote the original software.
       If you use this software in a product, an acknowledgment
       in the product documentation would be appreciated but
       is not required.

    2. Altered source versions must be plainly marked as such,
       and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any
       source distribution.
*/

#pragma once

#include "compileconfig.h"
#include "core.h"
#include "color.h"
#include "cirrlicht.h"

//! Enumeration for render passes.
/** A parameter passed to the registerNodeForRendering() method of the ISceneManager,
specifying when the node wants to be drawn in relation to the other nodes. */
enum E_SCENE_NODE_RENDER_PASS
{
    //! No pass currently active
    ESNRP_NONE =0,

    //! Camera pass. The active view is set up here. The very first pass.
    ESNRP_CAMERA =1,

    //! In this pass, lights are transformed into camera space and added to the driver
    ESNRP_LIGHT =2,

    //! This is used for sky boxes.
    ESNRP_SKY_BOX =4,

    //! All normal objects can use this for registering themselves.
    /** This value will never be returned by
    ISceneManager::getSceneNodeRenderPass(). The scene manager
    will determine by itself if an object is transparent or solid
    and register the object as SNRT_TRANSPARENT or SNRT_SOLD
    automatically if you call registerNodeForRendering with this
    value (which is default). Note that it will register the node
    only as ONE type. If your scene node has both solid and
    transparent material types register it twice (one time as
    SNRT_SOLID, the other time as SNRT_TRANSPARENT) and in the
    render() method call getSceneNodeRenderPass() to find out the
    current render pass and render only the corresponding parts of
    the node. */
    ESNRP_AUTOMATIC =24,

    //! Solid scene nodes or special scene nodes without materials.
    ESNRP_SOLID =8,

    //! Transparent scene nodes, drawn after solid nodes. They are sorted from back to front and drawn in that order.
    ESNRP_TRANSPARENT =16,

    //! Transparent effect scene nodes, drawn after Transparent nodes. They are sorted from back to front and drawn in that order.
    ESNRP_TRANSPARENT_EFFECT =32,

    //! Drawn after the solid nodes, before the transparent nodes, the time for drawing shadow volumes
    ESNRP_SHADOW =64
};

struct irr_IrrlichtDevice;

struct irr_ISceneManager;
typedef struct irr_ISceneManager irr_ISceneManager;

struct irr_ITexture;
struct irr_IMeshCache;
struct irr_IVideoDriver;
struct irr_IGUIEnvironment;
struct irr_IFileSystem;
struct irr_IVolumeLightSceneNode;
struct irr_IMeshSceneNode;
struct irr_ISceneNode;
struct irr_IAnimatedMeshSceneNode;
struct irr_ICameraSceneNode;
struct irr_SKeyMap;
struct irr_ILightSceneNode;
struct irr_IBillboardSceneNode;
struct irr_IParticleSystemSceneNode;
struct irr_ITerrainSceneNode;
struct irr_IMeshBuffer;
struct irr_IShader;
struct irr_IDummyTransformationSceneNode;
struct irr_ITextSceneNode;
struct irr_IGUIFont;
struct irr_IBillboardTextSceneNode;
struct irr_SMaterial;
struct irr_IImage;
struct irr_ISceneNodeAnimator;
struct irr_ISceneNodeAnimatorCollisionResponse;
struct irr_ITriangleSelector;
struct irr_IMetaTriangleSelector;
struct irr_IMeshLoader;
struct irr_ISceneLoader;
struct irr_ISceneCollisionManager;
struct irr_IMeshManipulator;
struct irr_SEvent;
struct irr_IAttributes;
struct irr_ISceneNodeFactory;
struct irr_ISceneNodeAnimatorFactory;
struct irr_ISceneUserDataSerializer;
struct irr_IMeshWriter;
struct irr_ISkinnedMesh;
struct irr_ILightManager;
struct irr_IGeometryCreator;

typedef struct irr_ITexture irr_ITexture;
typedef struct irr_IMeshCache irr_IMeshCache;
typedef struct irr_IVideoDriver irr_IVideoDriver;
typedef struct irr_IGUIEnvironment irr_IGUIEnvironment;
typedef struct irr_IFileSystem irr_IFileSystem;
typedef struct irr_IVolumeLightSceneNode irr_IVolumeLightSceneNode;
typedef struct irr_IMeshSceneNode irr_IMeshSceneNode;
typedef struct irr_ISceneNode irr_ISceneNode;
typedef struct irr_IAnimatedMeshSceneNode irr_IAnimatedMeshSceneNode;
typedef struct irr_ICameraSceneNode irr_ICameraSceneNode;
typedef struct irr_SKeyMap irr_SKeyMap;
typedef struct irr_ILightSceneNode irr_ILightSceneNode;
typedef struct irr_IBillboardSceneNode irr_IBillboardSceneNode;
typedef struct irr_IParticleSystemSceneNode irr_IParticleSystemSceneNode;
typedef struct irr_ITerrainSceneNode irr_ITerrainSceneNode;
typedef struct irr_IMeshBuffer irr_IMeshBuffer;
typedef struct irr_IShader irr_IShader;
typedef struct irr_IDummyTransformationSceneNode irr_IDummyTransformationSceneNode;
typedef struct irr_ITextSceneNode irr_ITextSceneNode;
typedef struct irr_IGUIFont irr_IGUIFont;
typedef struct irr_IBillboardTextSceneNode irr_IBillboardTextSceneNode;
typedef struct irr_SMaterial irr_SMaterial;
typedef struct irr_IImage irr_IImage;
typedef struct irr_ISceneNodeAnimator irr_ISceneNodeAnimator;
typedef struct irr_ISceneNodeAnimatorCollisionResponse irr_ISceneNodeAnimatorCollisionResponse;
typedef struct irr_ITriangleSelector irr_ITriangleSelector;
typedef struct irr_IMetaTriangleSelector irr_IMetaTriangleSelector;
typedef struct irr_IMeshLoader irr_IMeshLoader;
typedef struct irr_ISceneLoader irr_ISceneLoader;
typedef struct irr_ISceneCollisionManager irr_ISceneCollisionManager;
typedef struct irr_IMeshManipulator irr_IMeshManipulator;
typedef struct irr_SEvent irr_SEvent;
typedef struct irr_IAttributes irr_IAttributes;
typedef struct irr_ISceneNodeFactory irr_ISceneNodeFactory;
typedef struct irr_ISceneNodeAnimatorFactory irr_ISceneNodeAnimatorFactory;
typedef struct irr_ISceneUserDataSerializer irr_ISceneUserDataSerializer;
typedef struct irr_IMeshWriter irr_IMeshWriter;
typedef struct irr_ISkinnedMesh irr_ISkinnedMesh;
typedef struct irr_ILightManager irr_ILightManager;
typedef struct irr_IGeometryCreator irr_IGeometryCreator;

typedef struct irr_IMeshCache irr_IMeshCache;

CIRRLICHT_API irr_IAnimatedMesh* irr_ISceneManager_getMesh(irr_ISceneManager* smgr, const char* file);
CIRRLICHT_API irr_IMeshCache* irr_ISceneManager_getMeshCache(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IVideoDriver* irr_ISceneManager_getVideoDriver(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IGUIEnvironment* irr_ISceneManager_getGUIEnvironment(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IFileSystem* irr_ISceneManager_getFileSystem(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IVolumeLightSceneNode* irr_ISceneManager_addVolumeLightSceneNode(irr_ISceneManager* smgr, irr_ISceneNode* parent, int id, unsigned int subdivU, unsigned int subdivV, irr_SColor foot, irr_SColor tail, irr_vector3df position, irr_vector3df rotation, irr_vector3df scale);
CIRRLICHT_API irr_IMeshSceneNode* irr_ISceneManager_addCubeSceneNode(irr_ISceneManager* smgr, float size, irr_ISceneNode* parent, int id, irr_vector3df position, irr_vector3df rotation, irr_vector3df scale);
CIRRLICHT_API irr_IMeshSceneNode* irr_ISceneManager_addSphereSceneNode(irr_ISceneManager* smgr, float radius, int polyCount, irr_ISceneNode* parent, int id, irr_vector3df position, irr_vector3df rotation, irr_vector3df scale);
CIRRLICHT_API irr_IAnimatedMeshSceneNode* irr_ISceneManager_addAnimatedMeshSceneNode(irr_ISceneManager* smgr, irr_IAnimatedMesh* mesh, irr_ISceneNode* parent, int id, irr_vector3df position, irr_vector3df rotation, irr_vector3df scale, bool alsoAddIfMeshPointerZero);
CIRRLICHT_API irr_IMeshSceneNode* irr_ISceneManager_addMeshSceneNode(irr_ISceneManager* smgr, irr_IMesh* mesh, irr_ISceneNode* parent, int id, irr_vector3df position, irr_vector3df rotation, irr_vector3df scale, bool alsoAddIfMeshPointerZero);
CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_addWaterSurfaceSceneNode(irr_ISceneManager* smgr, irr_IMesh* mesh,
        float waveHeight, float waveSpeed, float waveLength,
        irr_ISceneNode* parent, int id,
        irr_vector3df position,
        irr_vector3df rotation,
        irr_vector3df scale);
CIRRLICHT_API irr_IMeshSceneNode* irr_ISceneManager_addOctreeSceneNode(irr_ISceneManager* smgr, irr_IAnimatedMesh* mesh, irr_ISceneNode* parent,
        int id, int minimalPolysPerNode, bool alsoAddIfMeshPointerZero);
CIRRLICHT_API irr_IMeshSceneNode* irr_ISceneManager_addOctreeSceneNode2(irr_ISceneManager* smgr, irr_IMesh* mesh, irr_ISceneNode* parent,
        int id, int minimalPolysPerNode, bool alsoAddIfMeshPointerZero);

CIRRLICHT_API irr_ICameraSceneNode* irr_ISceneManager_addCameraSceneNode(irr_ISceneManager* smgr, irr_ISceneNode* parent, irr_vector3df pos, irr_vector3df lookAt, int id, bool makeActive);
CIRRLICHT_API irr_ICameraSceneNode* irr_ISceneManager_addCameraSceneNodeMaya(irr_ISceneManager* smgr, irr_ISceneNode* parent,
        float rotateSpeed, float zoomSpeed,
        float translationSpeed, int id, float distance,
        bool makeActive);

CIRRLICHT_API irr_ICameraSceneNode* irr_ISceneManager_addCameraSceneNodeFPS(irr_ISceneManager* smgr, irr_ISceneNode* parent,
        float rotateSpeed, float moveSpeed, int id,
        irr_SKeyMap* keyMapArray, int keyMapSize, bool noVerticalMovement,
        float jumpSpeed, bool invertMouse,
        bool makeActive);

CIRRLICHT_API irr_ILightSceneNode* irr_ISceneManager_addLightSceneNode(irr_ISceneManager* smgr, irr_ISceneNode* parent,
        irr_vector3df position,
        irr_SColorf color,
        float radius, int id);

CIRRLICHT_API irr_IBillboardSceneNode* irr_ISceneManager_addBillboardSceneNode(irr_ISceneManager* smgr, irr_ISceneNode* parent,
        irr_dimension2df size,
        irr_vector3df position, int id,
        irr_SColor colorTop, irr_SColor colorBottom);

CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_addSkyBoxSceneNode(irr_ISceneManager* smgr, irr_ITexture* top, irr_ITexture* bottom,
        irr_ITexture* left, irr_ITexture* right, irr_ITexture* front,
        irr_ITexture* back, irr_ISceneNode* parent, int id);

CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_addSkyDomeSceneNode(irr_ISceneManager* smgr, irr_ITexture* texture,
        unsigned int horiRes, unsigned int vertRes,
        float texturePercentage, float spherePercentage,float radius,
        irr_ISceneNode* parent, int id);

CIRRLICHT_API irr_IParticleSystemSceneNode* irr_ISceneManager_addParticleSystemSceneNode(irr_ISceneManager* smgr,
        bool withDefaultEmitter, irr_ISceneNode* parent, int id,
        irr_vector3df position,
        irr_vector3df rotation,
        irr_vector3df scale);

CIRRLICHT_API irr_ITerrainSceneNode* irr_ISceneManager_addTerrainSceneNode(irr_ISceneManager* smgr,
        const char* heightMapFileName,
        irr_ISceneNode* parent, int id,
        irr_vector3df position,
        irr_vector3df rotation,
        irr_vector3df scale,
        irr_SColor vertexColor,
        int maxLOD, E_TERRAIN_PATCH_SIZE patchSize, int smoothFactor,
        bool addAlsoIfHeightmapEmpty);

CIRRLICHT_API irr_IMeshSceneNode* irr_ISceneManager_addQuake3SceneNode(irr_ISceneManager* smgr, const irr_IMeshBuffer* meshBuffer, const irr_IShader * shader,
        irr_ISceneNode* parent, int id
                                                        );

CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_addEmptySceneNode(irr_ISceneManager* smgr, irr_ISceneNode* parent=0, int id=-1);

CIRRLICHT_API irr_IDummyTransformationSceneNode* irr_ISceneManager_addDummyTransformationSceneNode(irr_ISceneManager* smgr,
        irr_ISceneNode* parent, int id);

CIRRLICHT_API irr_ITextSceneNode* irr_ISceneManager_addTextSceneNode(irr_ISceneManager* smgr, irr_IGUIFont* font, const wchar_t* text,
        irr_SColor color,
        irr_ISceneNode* parent, irr_vector3df position,
        int id=-1);

CIRRLICHT_API irr_IBillboardTextSceneNode* irr_ISceneManager_addBillboardTextSceneNode(irr_ISceneManager* smgr, irr_IGUIFont* font, const wchar_t* text,
        irr_ISceneNode* parent,
        irr_dimension2df size ,
        irr_vector3df position, int id=-1,
        irr_SColor colorTop, irr_SColor colorBottom);

CIRRLICHT_API irr_IAnimatedMesh* irr_ISceneManager_addHillPlaneMesh(irr_ISceneManager* smgr, const char* name,
        irr_dimension2df tileSize, irr_dimension2du tileCount,
        irr_SMaterial* material, float hillHeight,
        irr_dimension2df countHills,
        irr_dimension2df textureRepeatCount);

CIRRLICHT_API irr_IAnimatedMesh* irr_ISceneManager_addTerrainMesh(irr_ISceneManager* smgr, const char* meshname,
        irr_IImage* texture, irr_IImage* heightmap,
        irr_dimension2df stretchSize,
        float maxHeight,
        irr_dimension2du defaultVertexBlockSize);

CIRRLICHT_API irr_IAnimatedMesh* irr_ISceneManager_addArrowMesh(irr_ISceneManager* smgr, const char* name,
        irr_SColor vtxColorCylinder,
        irr_SColor vtxColorCone,
        unsigned int tesselationCylinder, unsigned int tesselationCone=8,
        float height, float cylinderHeight,
        float widthCylinder, float widthCone);

CIRRLICHT_API irr_IAnimatedMesh* irr_ISceneManager_addSphereMesh(irr_ISceneManager* smgr, const char* name,
        float radius, unsigned int polyCountX,
        unsigned int polyCountY);

CIRRLICHT_API irr_IAnimatedMesh* irr_ISceneManager_addVolumeLightMesh(irr_ISceneManager* smgr, const char* name,
        const unsigned int SubdivideU, const unsigned int SubdivideV,
        irr_SColor FootColor,
        irr_SColor TailColor);

CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_getRootSceneNode(irr_ISceneManager* smgr);

CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_getSceneNodeFromId(irr_ISceneManager* smgr, unsigned int id, irr_ISceneNode* start=0);
CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_getSceneNodeFromName(irr_ISceneManager* smgr, const char* name, irr_ISceneNode* start=0);
CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_getSceneNodeFromType(irr_ISceneManager* smgr, ESCENE_NODE_TYPE type, irr_ISceneNode* start=0);
CIRRLICHT_API void irr_ISceneManager_getSceneNodesFromType(irr_ISceneManager* smgr, ESCENE_NODE_TYPE type,
        irr_array* outNodes,
        irr_ISceneNode* start=0);
CIRRLICHT_API irr_ICameraSceneNode* irr_ISceneManager_getActiveCamera(irr_ISceneManager* smgr);
CIRRLICHT_API void irr_ISceneManager_setActiveCamera(irr_ISceneManager* smgr, irr_ICameraSceneNode* camera);
CIRRLICHT_API void irr_ISceneManager_setShadowColor(irr_ISceneManager* smgr, irr_SColor color =);
CIRRLICHT_API irr_SColor irr_ISceneManager_getShadowColor(irr_ISceneManager* smgr);
CIRRLICHT_API unsigned int irr_ISceneManager_registerNodeForRendering(irr_ISceneManager* smgr, irr_ISceneNode* node,
        E_SCENE_NODE_RENDER_PASS pass);

CIRRLICHT_API void irr_ISceneManager_drawAll(irr_ISceneManager* smgr);
CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createRotationAnimator(irr_ISceneManager* smgr, irr_vector3df rotationSpeed);
CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createFlyCircleAnimator(irr_ISceneManager* smgr,
        irr_vector3df center,
        float radius=100.f, float speed=0.001f,
        irr_vector3df direction= {0.f, 1.f, 0.f},
        float startPosition = 0.f,
        float radiusEllipsoid = 0.f);

CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createFlyStraightAnimator(irr_ISceneManager* smgr, irr_vector3df startPoint, irr_vector3df endPoint, unsigned int timeForWay, bool loop=false, bool pingpong = false);

CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createTextureAnimator(irr_ISceneManager* smgr, irr_array* textures, int timePerFrame, bool loop=true);
CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createDeleteAnimator(irr_ISceneManager* smgr, unsigned int timeMs);
CIRRLICHT_API irr_ISceneNodeAnimatorCollisionResponse* irr_ISceneManager_createCollisionResponseAnimator(irr_ISceneManager* smgr,
        irr_ITriangleSelector* world, irr_ISceneNode* sceneNode,
        irr_vector3df ellipsoidRadius = {30,60,30},
        irr_vector3df gravityPerSecond = {0,-10.0f,0},
        irr_vector3df ellipsoidTranslation = {0,0,0},
        float slidingValue = 0.0005f);

CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createFollowSplineAnimator(irr_ISceneManager* smgr, int startTime,
        irr_array* points,
        float speed = 1.0f, float tightness = 0.5f, bool loop=true, bool pingpong=false);

CIRRLICHT_API irr_ITriangleSelector* irr_ISceneManager_createTriangleSelector(irr_ISceneManager* smgr, irr_IMesh* mesh, irr_ISceneNode* node);
CIRRLICHT_API irr_ITriangleSelector* irr_ISceneManager_createTriangleSelector2(irr_ISceneManager* smgr, irr_IAnimatedMeshSceneNode* node);
CIRRLICHT_API irr_ITriangleSelector* irr_ISceneManager_createTriangleSelectorFromBoundingBox(irr_ISceneManager* smgr, irr_ISceneNode* node);
CIRRLICHT_API irr_ITriangleSelector* irr_ISceneManager_createOctreeTriangleSelector(irr_ISceneManager* smgr, irr_IMesh* mesh,
        irr_ISceneNode* node, int minimalPolysPerNode=32);
CIRRLICHT_API irr_IMetaTriangleSelector* irr_ISceneManager_createMetaTriangleSelector(irr_ISceneManager* smgr);
CIRRLICHT_API irr_ITriangleSelector* irr_ISceneManager_createTerrainTriangleSelector(irr_ISceneManager* smgr,
        irr_ITerrainSceneNode* node, int LOD=0);
CIRRLICHT_API void irr_ISceneManager_addExternalMeshLoader(irr_ISceneManager* smgr, irr_IMeshLoader* externalLoader);
CIRRLICHT_API unsigned int irr_ISceneManager_getMeshLoaderCount(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IMeshLoader* irr_ISceneManager_getMeshLoader(irr_ISceneManager* smgr, unsigned int index);
CIRRLICHT_API void irr_ISceneManager_addExternalSceneLoader(irr_ISceneManager* smgr, irr_ISceneLoader* externalLoader);
CIRRLICHT_API unsigned int irr_ISceneManager_getSceneLoaderCount(irr_ISceneManager* smgr);
CIRRLICHT_API irr_ISceneLoader* irr_ISceneManager_getSceneLoader(irr_ISceneManager* smgr, unsigned int index);
CIRRLICHT_API irr_ISceneCollisionManager* irr_ISceneManager_getSceneCollisionManager(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IMeshManipulator* irr_ISceneManager_getMeshManipulator(irr_ISceneManager* smgr);
CIRRLICHT_API void irr_ISceneManager_addToDeletionQueue(irr_ISceneManager* smgr, irr_ISceneNode* node);
CIRRLICHT_API bool irr_ISceneManager_postEventFromUser(irr_ISceneManager* smgr, irr_SEvent* event);
CIRRLICHT_API void irr_ISceneManager_clear(irr_ISceneManager* smgr);
CIRRLICHT_API irr_IAttributes* irr_ISceneManager_getParameters(irr_ISceneManager* smgr);
CIRRLICHT_API E_SCENE_NODE_RENDER_PASS irr_ISceneManager_getSceneNodeRenderPass(irr_ISceneManager* smgr);
CIRRLICHT_API irr_ISceneNodeFactory* irr_ISceneManager_getDefaultSceneNodeFactory(irr_ISceneManager* smgr);
CIRRLICHT_API void irr_ISceneManager_registerSceneNodeFactory(irr_ISceneManager* smgr, irr_ISceneNodeFactory* factoryToAdd);
CIRRLICHT_API unsigned int irr_ISceneManager_getRegisteredSceneNodeFactoryCount(irr_ISceneManager* smgr);
CIRRLICHT_API irr_ISceneNodeFactory* irr_ISceneManager_getSceneNodeFactory(irr_ISceneManager* smgr, unsigned int index);
CIRRLICHT_API irr_ISceneNodeAnimatorFactory* irr_ISceneManager_getDefaultSceneNodeAnimatorFactory(irr_ISceneManager* smgr);
CIRRLICHT_API void irr_ISceneManager_registerSceneNodeAnimatorFactory(irr_ISceneManager* smgr, irr_ISceneNodeAnimatorFactory* factoryToAdd);
CIRRLICHT_API unsigned int irr_ISceneManager_getRegisteredSceneNodeAnimatorFactoryCount(irr_ISceneManager* smgr);
CIRRLICHT_API irr_ISceneNodeAnimatorFactory* irr_ISceneManager_getSceneNodeAnimatorFactory(irr_ISceneManager* smgr, unsigned int index);
CIRRLICHT_API const char* irr_ISceneManager_getSceneNodeTypeName(irr_ISceneManager* smgr, ESCENE_NODE_TYPE type);
CIRRLICHT_API const char* irr_ISceneManager_getAnimatorTypeName(irr_ISceneManager* smgr, ESCENE_NODE_ANIMATOR_TYPE type);
CIRRLICHT_API irr_ISceneNode* irr_ISceneManager_addSceneNode(irr_ISceneManager* smgr, const char* sceneNodeTypeName, irr_ISceneNode* parent=0);
CIRRLICHT_API irr_ISceneNodeAnimator* irr_ISceneManager_createSceneNodeAnimator(irr_ISceneManager* smgr, const char* typeName, irr_ISceneNode* target=0);
CIRRLICHT_API irr_ISceneManager* irr_ISceneManager_createNewSceneManager(irr_ISceneManager* smgr, bool cloneContent=false);
CIRRLICHT_API bool irr_ISceneManager_saveScene(irr_ISceneManager* smgr, const char* filename, irr_ISceneUserDataSerializer* userDataSerializer=0, irr_ISceneNode* node=0);
CIRRLICHT_API bool irr_ISceneManager_loadScene(irr_ISceneManager* smgr, const char* filename, irr_ISceneUserDataSerializer* userDataSerializer=0, irr_ISceneNode* rootNode=0);
CIRRLICHT_API irr_IMeshWriter* irr_ISceneManager_createMeshWriter(irr_ISceneManager* smgr, EMESH_WRITER_TYPE type);
CIRRLICHT_API irr_ISkinnedMesh* irr_ISceneManager_createSkinnedMesh(irr_ISceneManager* smgr);
CIRRLICHT_API void irr_ISceneManager_setAmbientLight(irr_ISceneManager* smgr, irr_SColorf ambientColor);
CIRRLICHT_API irr_SColorf irr_ISceneManager_getAmbientLight(irr_ISceneManager* smgr);
CIRRLICHT_API void irr_ISceneManager_setLightManager(irr_ISceneManager* smgr, irr_ILightManager* lightManager);
CIRRLICHT_API E_SCENE_NODE_RENDER_PASS irr_ISceneManager_getCurrentRenderPass(irr_ISceneManager* smgr);
CIRRLICHT_API const irr_IGeometryCreator* irr_ISceneManager_getGeometryCreator(irr_ISceneManager* smgr);
CIRRLICHT_API bool irr_ISceneManager_isCulled(irr_ISceneManager* smgr, const irr_ISceneNode* node);
