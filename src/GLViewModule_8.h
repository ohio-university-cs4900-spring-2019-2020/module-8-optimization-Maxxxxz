#pragma once

#include "MGLFrustum.h"
#include "GLView.h"

namespace Aftr
{
   class Camera;
   
/**
   \class GLViewModule_8
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewModule_8 : public GLView
{
public:
   static GLViewModule_8* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewModule_8();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createModule_8WayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );

protected:
   GLViewModule_8( const std::vector< std::string >& args );
   virtual void onCreate();
   bool isInFrustum(WO* fr, float hfov, WO* wo);
   void createRandomCube();

   WO* worldFr;
   WO* playerFr;
   WorldList* objLst;
   short numboxes = 0;
};

/** \} */

} //namespace Aftr
