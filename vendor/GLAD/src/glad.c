#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glad/glad.h"

/*
 * glad_get_proc_from_userptr хранит указатель на SDL_GL_GetProcAddress.
 * SDL3 объявляет его как SDL_FunctionPointer SDL_GL_GetProcAddress(const char*).
 * Мы храним его как void(*)(void) и при вызове делаем приведение через
 * union, чтобы избежать UB при касте между указателями на функции.
 */
typedef void (*GLfuncptr)(void);
typedef GLfuncptr (*GLADgetproctype)(const char*);

static GLADgetproctype glad_getproc = NULL;

static GLfuncptr glad_get_proc(const char *name) {
    if (glad_getproc == NULL) return NULL;
    return glad_getproc(name);
}

PFNGLCULLFACEPROC glad_glCullFace = NULL;
PFNGLFRONTFACEPROC glad_glFrontFace = NULL;
PFNGLHINTPROC glad_glHint = NULL;
PFNGLLINEWIDTHPROC glad_glLineWidth = NULL;
PFNGLPOINTSIZEPROC glad_glPointSize = NULL;
PFNGLPOLYGONMODEPROC glad_glPolygonMode = NULL;
PFNGLSCISSORPROC glad_glScissor = NULL;
PFNGLTEXPARAMETERFPROC glad_glTexParameterf = NULL;
PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv = NULL;
PFNGLTEXPARAMETERIPROC glad_glTexParameteri = NULL;
PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv = NULL;
PFNGLTEXIMAGE2DPROC glad_glTexImage2D = NULL;
PFNGLDRAWBUFFERPROC glad_glDrawBuffer = NULL;
PFNGLCLEARPROC glad_glClear = NULL;
PFNGLCLEARCOLORPROC glad_glClearColor = NULL;
PFNGLCLEARDEPTHPROC glad_glClearDepth = NULL;
PFNGLCLEARSTENCILPROC glad_glClearStencil = NULL;
PFNGLCOLORMASKPROC glad_glColorMask = NULL;
PFNGLDEPTHMASKPROC glad_glDepthMask = NULL;
PFNGLDISABLEPROC glad_glDisable = NULL;
PFNGLENABLEPROC glad_glEnable = NULL;
PFNGLFINISHPROC glad_glFinish = NULL;
PFNGLFLUSHPROC glad_glFlush = NULL;
PFNGLBLENDFUNCPROC glad_glBlendFunc = NULL;
PFNGLLOGICOPPROC glad_glLogicOp = NULL;
PFNGLSTENCILFUNCPROC glad_glStencilFunc = NULL;
PFNGLSTENCILOPPROC glad_glStencilOp = NULL;
PFNGLDEPTHFUNCPROC glad_glDepthFunc = NULL;
PFNGLPIXELSTOREFPROC glad_glPixelStoref = NULL;
PFNGLPIXELSTOREIPROC glad_glPixelStorei = NULL;
PFNGLREADBUFFERPROC glad_glReadBuffer = NULL;
PFNGLREADPIXELSPROC glad_glReadPixels = NULL;
PFNGLGETERRORPROC glad_glGetError = NULL;
PFNGLGETFLOATVPROC glad_glGetFloatv = NULL;
PFNGLGETINTEGERVPROC glad_glGetIntegerv = NULL;
PFNGLGETSTRINGPROC glad_glGetString = NULL;
PFNGLGETTEXIMAGEPROC glad_glGetTexImage = NULL;
PFNGLVIEWPORTPROC glad_glViewport = NULL;
PFNGLDRAWARRAYSPROC glad_glDrawArrays = NULL;
PFNGLDRAWELEMENTSPROC glad_glDrawElements = NULL;
PFNGLGENTEXTURESPROC glad_glGenTextures = NULL;
PFNGLDELETETEXTURESPROC glad_glDeleteTextures = NULL;
PFNGLBINDTEXTUREPROC glad_glBindTexture = NULL;
PFNGLACTIVETEXTUREPROC glad_glActiveTexture = NULL;
PFNGLGENBUFFERSPROC glad_glGenBuffers = NULL;
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = NULL;
PFNGLBINDBUFFERPROC glad_glBindBuffer = NULL;
PFNGLBUFFERDATAPROC glad_glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = NULL;
PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays = NULL;
PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays = NULL;
PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray = NULL;
PFNGLCREATESHADERPROC glad_glCreateShader = NULL;
PFNGLDELETESHADERPROC glad_glDeleteShader = NULL;
PFNGLSHADERSOURCEPROC glad_glShaderSource = NULL;
PFNGLCOMPILESHADERPROC glad_glCompileShader = NULL;
PFNGLGETSHADERIVPROC glad_glGetShaderiv = NULL;
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = NULL;
PFNGLCREATEPROGRAMPROC glad_glCreateProgram = NULL;
PFNGLDELETEPROGRAMPROC glad_glDeleteProgram = NULL;
PFNGLATTACHSHADERPROC glad_glAttachShader = NULL;
PFNGLLINKPROGRAMPROC glad_glLinkProgram = NULL;
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = NULL;
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = NULL;
PFNGLUSEPROGRAMPROC glad_glUseProgram = NULL;
PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation = NULL;
PFNGLUNIFORM1IPROC glad_glUniform1i = NULL;
PFNGLUNIFORM1FPROC glad_glUniform1f = NULL;
PFNGLUNIFORM2FPROC glad_glUniform2f = NULL;
PFNGLUNIFORM3FPROC glad_glUniform3f = NULL;
PFNGLUNIFORM4FPROC glad_glUniform4f = NULL;
PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv = NULL;
PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap = NULL;
PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers = NULL;
PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers = NULL;
PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D = NULL;
PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers = NULL;
PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers = NULL;
PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer = NULL;
PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer = NULL;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample = NULL;
PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer = NULL;
PFNGLGETSTRINGIPROC glad_glGetStringi = NULL;

static void glad_load_gl_procs(void) {
    glad_glCullFace = (PFNGLCULLFACEPROC)glad_get_proc("glCullFace");
    glad_glFrontFace = (PFNGLFRONTFACEPROC)glad_get_proc("glFrontFace");
    glad_glHint = (PFNGLHINTPROC)glad_get_proc("glHint");
    glad_glLineWidth = (PFNGLLINEWIDTHPROC)glad_get_proc("glLineWidth");
    glad_glPointSize = (PFNGLPOINTSIZEPROC)glad_get_proc("glPointSize");
    glad_glPolygonMode = (PFNGLPOLYGONMODEPROC)glad_get_proc("glPolygonMode");
    glad_glScissor = (PFNGLSCISSORPROC)glad_get_proc("glScissor");
    glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC)glad_get_proc("glTexParameterf");
    glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)glad_get_proc("glTexParameterfv");
    glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC)glad_get_proc("glTexParameteri");
    glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)glad_get_proc("glTexParameteriv");
    glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC)glad_get_proc("glTexImage2D");
    glad_glDrawBuffer = (PFNGLDRAWBUFFERPROC)glad_get_proc("glDrawBuffer");
    glad_glClear = (PFNGLCLEARPROC)glad_get_proc("glClear");
    glad_glClearColor = (PFNGLCLEARCOLORPROC)glad_get_proc("glClearColor");
    glad_glClearDepth = (PFNGLCLEARDEPTHPROC)glad_get_proc("glClearDepth");
    glad_glClearStencil = (PFNGLCLEARSTENCILPROC)glad_get_proc("glClearStencil");
    glad_glColorMask = (PFNGLCOLORMASKPROC)glad_get_proc("glColorMask");
    glad_glDepthMask = (PFNGLDEPTHMASKPROC)glad_get_proc("glDepthMask");
    glad_glDisable = (PFNGLDISABLEPROC)glad_get_proc("glDisable");
    glad_glEnable = (PFNGLENABLEPROC)glad_get_proc("glEnable");
    glad_glFinish = (PFNGLFINISHPROC)glad_get_proc("glFinish");
    glad_glFlush = (PFNGLFLUSHPROC)glad_get_proc("glFlush");
    glad_glBlendFunc = (PFNGLBLENDFUNCPROC)glad_get_proc("glBlendFunc");
    glad_glLogicOp = (PFNGLLOGICOPPROC)glad_get_proc("glLogicOp");
    glad_glStencilFunc = (PFNGLSTENCILFUNCPROC)glad_get_proc("glStencilFunc");
    glad_glStencilOp = (PFNGLSTENCILOPPROC)glad_get_proc("glStencilOp");
    glad_glDepthFunc = (PFNGLDEPTHFUNCPROC)glad_get_proc("glDepthFunc");
    glad_glPixelStoref = (PFNGLPIXELSTOREFPROC)glad_get_proc("glPixelStoref");
    glad_glPixelStorei = (PFNGLPIXELSTOREIPROC)glad_get_proc("glPixelStorei");
    glad_glReadBuffer = (PFNGLREADBUFFERPROC)glad_get_proc("glReadBuffer");
    glad_glReadPixels = (PFNGLREADPIXELSPROC)glad_get_proc("glReadPixels");
    glad_glGetError = (PFNGLGETERRORPROC)glad_get_proc("glGetError");
    glad_glGetFloatv = (PFNGLGETFLOATVPROC)glad_get_proc("glGetFloatv");
    glad_glGetIntegerv = (PFNGLGETINTEGERVPROC)glad_get_proc("glGetIntegerv");
    glad_glGetString = (PFNGLGETSTRINGPROC)glad_get_proc("glGetString");
    glad_glGetTexImage = (PFNGLGETTEXIMAGEPROC)glad_get_proc("glGetTexImage");
    glad_glViewport = (PFNGLVIEWPORTPROC)glad_get_proc("glViewport");
    glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)glad_get_proc("glDrawArrays");
    glad_glDrawElements = (PFNGLDRAWELEMENTSPROC)glad_get_proc("glDrawElements");
    glad_glGenTextures = (PFNGLGENTEXTURESPROC)glad_get_proc("glGenTextures");
    glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC)glad_get_proc("glDeleteTextures");
    glad_glBindTexture = (PFNGLBINDTEXTUREPROC)glad_get_proc("glBindTexture");
    glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)glad_get_proc("glActiveTexture");
    glad_glGenBuffers = (PFNGLGENBUFFERSPROC)glad_get_proc("glGenBuffers");
    glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glad_get_proc("glDeleteBuffers");
    glad_glBindBuffer = (PFNGLBINDBUFFERPROC)glad_get_proc("glBindBuffer");
    glad_glBufferData = (PFNGLBUFFERDATAPROC)glad_get_proc("glBufferData");
    glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)glad_get_proc("glBufferSubData");
    glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glad_get_proc("glGenVertexArrays");
    glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)glad_get_proc("glDeleteVertexArrays");
    glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glad_get_proc("glBindVertexArray");
    glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glad_get_proc("glVertexAttribPointer");
    glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glad_get_proc("glEnableVertexAttribArray");
    glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)glad_get_proc("glDisableVertexAttribArray");
    glad_glCreateShader = (PFNGLCREATESHADERPROC)glad_get_proc("glCreateShader");
    glad_glDeleteShader = (PFNGLDELETESHADERPROC)glad_get_proc("glDeleteShader");
    glad_glShaderSource = (PFNGLSHADERSOURCEPROC)glad_get_proc("glShaderSource");
    glad_glCompileShader = (PFNGLCOMPILESHADERPROC)glad_get_proc("glCompileShader");
    glad_glGetShaderiv = (PFNGLGETSHADERIVPROC)glad_get_proc("glGetShaderiv");
    glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glad_get_proc("glGetShaderInfoLog");
    glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)glad_get_proc("glCreateProgram");
    glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)glad_get_proc("glDeleteProgram");
    glad_glAttachShader = (PFNGLATTACHSHADERPROC)glad_get_proc("glAttachShader");
    glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)glad_get_proc("glLinkProgram");
    glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glad_get_proc("glGetProgramiv");
    glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glad_get_proc("glGetProgramInfoLog");
    glad_glUseProgram = (PFNGLUSEPROGRAMPROC)glad_get_proc("glUseProgram");
    glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glad_get_proc("glGetUniformLocation");
    glad_glUniform1i = (PFNGLUNIFORM1IPROC)glad_get_proc("glUniform1i");
    glad_glUniform1f = (PFNGLUNIFORM1FPROC)glad_get_proc("glUniform1f");
    glad_glUniform2f = (PFNGLUNIFORM2FPROC)glad_get_proc("glUniform2f");
    glad_glUniform3f = (PFNGLUNIFORM3FPROC)glad_get_proc("glUniform3f");
    glad_glUniform4f = (PFNGLUNIFORM4FPROC)glad_get_proc("glUniform4f");
    glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glad_get_proc("glUniformMatrix4fv");
    glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)glad_get_proc("glGenerateMipmap");
    glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)glad_get_proc("glGenFramebuffers");
    glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)glad_get_proc("glDeleteFramebuffers");
    glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)glad_get_proc("glBindFramebuffer");
    glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)glad_get_proc("glCheckFramebufferStatus");
    glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)glad_get_proc("glFramebufferTexture2D");
    glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)glad_get_proc("glGenRenderbuffers");
    glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)glad_get_proc("glDeleteRenderbuffers");
    glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)glad_get_proc("glBindRenderbuffer");
    glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)glad_get_proc("glRenderbufferStorage");
    glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)glad_get_proc("glFramebufferRenderbuffer");
    glad_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)glad_get_proc("glTexImage2DMultisample");
    glad_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)glad_get_proc("glBlitFramebuffer");
    glad_glGetStringi = (PFNGLGETSTRINGIPROC)glad_get_proc("glGetStringi");
}

int gladLoadGLLoader(GLADloadproc load) {
    /* SDL3::SDL_GL_GetProcAddress возвращает SDL_FunctionPointer (void(*)(void)).
       Кастим через union чтобы избежать UB при приведении указателей на функции. */
    union { GLADloadproc voidfn; GLADgetproctype getproc; } u;
    u.voidfn = load;
    glad_getproc = u.getproc;
    glad_load_gl_procs();
    if (glad_glGetString == NULL) return 0;
    return 1;
}
