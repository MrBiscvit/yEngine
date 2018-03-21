#pragma once

#include <yEmma/yEmma.h>

#if defined(yUSE_OPENGL)
#include <GL/glew.h>
#include <string>
#include <vector>

#if defined(yCC_MSVC)
#pragma comment(lib, "opengl32.lib")
#endif

class yEMMA_API yOpenGL
{
public:
	inline static void init() { glewExperimental = true; glewInit(); }
	inline static void terminate() {  }

	inline static std::string vendor() { return (const char*)glGetString(GL_VENDOR); }
	inline static std::string renderer() { return (const char*)glGetString(GL_RENDERER); }
	inline static std::string version() { return (const char*)glGetString(GL_VERSION); }
	inline static std::string glslVersion() { return (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION); }

	inline static bool isSupported(const char * name) { return glewIsSupported(name); }
};

// Implementation
#include <yEmma/private/yOpenGL.inl>
#endif