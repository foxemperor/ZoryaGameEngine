#ifndef __glad_h_
#define __glad_h_

#ifdef __gl_h_
  #error OpenGL header already included, remove this include, GLAD already provides it
#endif
#define __gl_h_

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
typedef int64_t GLint64;
typedef uint64_t GLuint64;
#elif defined(_WIN32)
typedef signed   __int64  GLint64;
typedef unsigned __int64  GLuint64;
#else
#include <inttypes.h>
typedef int64_t GLint64;
typedef uint64_t GLuint64;
#endif
#define GLEXT_64_TYPES_DEFINED
#endif

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLclampx;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef unsigned short GLhalfARB;
typedef unsigned short GLhalf;
typedef GLint GLfixed;
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCKHR)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar *message, void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_NONE                           0
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000

#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006

#define GL_DEPTH_TEST                     0x0B71
#define GL_BLEND                          0x0BE2
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303

#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_STATIC_DRAW                    0x88B4
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_STREAM_DRAW                    0x88E0

#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84

#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE0                       0x84C0
#define GL_RGBA                           0x1908
#define GL_RGB                            0x1907
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_FLOAT                          0x1406
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_LINEAR                         0x2601
#define GL_NEAREST                        0x2600
#define GL_REPEAT                         0x2901
#define GL_CLAMP_TO_EDGE                  0x812F

#define GL_FRAMEBUFFER                    0x8D40
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_RENDERBUFFER                   0x8D41
#define GL_DEPTH_COMPONENT                0x1902
#define GL_DEPTH_COMPONENT24              0x81A6

#define GL_VERTEX_ARRAY_BINDING           0x85B5
#define GL_CURRENT_PROGRAM                0x8B8D

#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C

typedef void   (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
typedef void   (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
typedef void   (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void   (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void   (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void   (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void   (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void   (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void   (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void   (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void   (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void   (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void   (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum buf);
typedef void   (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void   (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void   (APIENTRYP PFNGLCLEARDEPTHPROC) (GLclampd depth);
typedef void   (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void   (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void   (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void   (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void   (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void   (APIENTRYP PFNGLFINISHPROC) (void);
typedef void   (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void   (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void   (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void   (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void   (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void   (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void   (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void   (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void   (APIENTRYP PFNGLREADBUFFERPROC) (GLenum src);
typedef void   (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
typedef void   (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *data);
typedef void   (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *data);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void   (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void   (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void   (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void   (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void   (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
typedef void   (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
typedef void   (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void   (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void   (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
typedef void   (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint *buffers);
typedef void   (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void   (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void   (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void   (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint *arrays);
typedef void   (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint *arrays);
typedef void   (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void   (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void   (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void   (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void   (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void   (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void   (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef void   (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint *params);
typedef void   (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef void   (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void   (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void   (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void   (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint *params);
typedef void   (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void   (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef GLint  (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar *name);
typedef void   (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void   (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void   (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void   (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void   (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void   (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void   (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void   (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint *framebuffers);
typedef void   (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint *framebuffers);
typedef void   (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void   (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void   (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint *renderbuffers);
typedef void   (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint *renderbuffers);
typedef void   (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void   (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void   (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void   (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void   (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);

extern PFNGLCULLFACEPROC glad_glCullFace;
extern PFNGLFRONTFACEPROC glad_glFrontFace;
extern PFNGLHINTPROC glad_glHint;
extern PFNGLLINEWIDTHPROC glad_glLineWidth;
extern PFNGLPOINTSIZEPROC glad_glPointSize;
extern PFNGLPOLYGONMODEPROC glad_glPolygonMode;
extern PFNGLSCISSORPROC glad_glScissor;
extern PFNGLTEXPARAMETERFPROC glad_glTexParameterf;
extern PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv;
extern PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
extern PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv;
extern PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
extern PFNGLDRAWBUFFERPROC glad_glDrawBuffer;
extern PFNGLCLEARPROC glad_glClear;
extern PFNGLCLEARCOLORPROC glad_glClearColor;
extern PFNGLCLEARDEPTHPROC glad_glClearDepth;
extern PFNGLCLEARSTENCILPROC glad_glClearStencil;
extern PFNGLCOLORMASKPROC glad_glColorMask;
extern PFNGLDEPTHMASKPROC glad_glDepthMask;
extern PFNGLDISABLEPROC glad_glDisable;
extern PFNGLENABLEPROC glad_glEnable;
extern PFNGLFINISHPROC glad_glFinish;
extern PFNGLFLUSHPROC glad_glFlush;
extern PFNGLBLENDFUNCPROC glad_glBlendFunc;
extern PFNGLLOGICOPPROC glad_glLogicOp;
extern PFNGLSTENCILFUNCPROC glad_glStencilFunc;
extern PFNGLSTENCILOPPROC glad_glStencilOp;
extern PFNGLDEPTHFUNCPROC glad_glDepthFunc;
extern PFNGLPIXELSTOREFPROC glad_glPixelStoref;
extern PFNGLPIXELSTOREIPROC glad_glPixelStorei;
extern PFNGLREADBUFFERPROC glad_glReadBuffer;
extern PFNGLREADPIXELSPROC glad_glReadPixels;
extern PFNGLGETERRORPROC glad_glGetError;
extern PFNGLGETFLOATVPROC glad_glGetFloatv;
extern PFNGLGETINTEGERVPROC glad_glGetIntegerv;
extern PFNGLGETSTRINGPROC glad_glGetString;
extern PFNGLGETTEXIMAGEPROC glad_glGetTexImage;
extern PFNGLVIEWPORTPROC glad_glViewport;
extern PFNGLDRAWARRAYSPROC glad_glDrawArrays;
extern PFNGLDRAWELEMENTSPROC glad_glDrawElements;
extern PFNGLGENTEXTURESPROC glad_glGenTextures;
extern PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
extern PFNGLBINDTEXTUREPROC glad_glBindTexture;
extern PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
extern PFNGLGENBUFFERSPROC glad_glGenBuffers;
extern PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
extern PFNGLBINDBUFFERPROC glad_glBindBuffer;
extern PFNGLBUFFERDATAPROC glad_glBufferData;
extern PFNGLBUFFERSUBDATAPROC glad_glBufferSubData;
extern PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays;
extern PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray;
extern PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;
extern PFNGLCREATESHADERPROC glad_glCreateShader;
extern PFNGLDELETESHADERPROC glad_glDeleteShader;
extern PFNGLSHADERSOURCEPROC glad_glShaderSource;
extern PFNGLCOMPILESHADERPROC glad_glCompileShader;
extern PFNGLGETSHADERIVPROC glad_glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
extern PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
extern PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
extern PFNGLATTACHSHADERPROC glad_glAttachShader;
extern PFNGLLINKPROGRAMPROC glad_glLinkProgram;
extern PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
extern PFNGLUSEPROGRAMPROC glad_glUseProgram;
extern PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
extern PFNGLUNIFORM1IPROC glad_glUniform1i;
extern PFNGLUNIFORM1FPROC glad_glUniform1f;
extern PFNGLUNIFORM2FPROC glad_glUniform2f;
extern PFNGLUNIFORM3FPROC glad_glUniform3f;
extern PFNGLUNIFORM4FPROC glad_glUniform4f;
extern PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
extern PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
extern PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers;
extern PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers;
extern PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D;
extern PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers;
extern PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers;
extern PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer;
extern PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer;
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample;
extern PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer;
extern PFNGLGETSTRINGIPROC glad_glGetStringi;

#define glCullFace                  glad_glCullFace
#define glFrontFace                 glad_glFrontFace
#define glHint                      glad_glHint
#define glLineWidth                 glad_glLineWidth
#define glPointSize                 glad_glPointSize
#define glPolygonMode               glad_glPolygonMode
#define glScissor                   glad_glScissor
#define glTexParameterf             glad_glTexParameterf
#define glTexParameterfv            glad_glTexParameterfv
#define glTexParameteri             glad_glTexParameteri
#define glTexParameteriv            glad_glTexParameteriv
#define glTexImage2D                glad_glTexImage2D
#define glDrawBuffer                glad_glDrawBuffer
#define glClear                     glad_glClear
#define glClearColor                glad_glClearColor
#define glClearDepth                glad_glClearDepth
#define glClearStencil              glad_glClearStencil
#define glColorMask                 glad_glColorMask
#define glDepthMask                 glad_glDepthMask
#define glDisable                   glad_glDisable
#define glEnable                    glad_glEnable
#define glFinish                    glad_glFinish
#define glFlush                     glad_glFlush
#define glBlendFunc                 glad_glBlendFunc
#define glLogicOp                   glad_glLogicOp
#define glStencilFunc               glad_glStencilFunc
#define glStencilOp                 glad_glStencilOp
#define glDepthFunc                 glad_glDepthFunc
#define glPixelStoref               glad_glPixelStoref
#define glPixelStorei               glad_glPixelStorei
#define glReadBuffer                glad_glReadBuffer
#define glReadPixels                glad_glReadPixels
#define glGetError                  glad_glGetError
#define glGetFloatv                 glad_glGetFloatv
#define glGetIntegerv               glad_glGetIntegerv
#define glGetString                 glad_glGetString
#define glGetTexImage               glad_glGetTexImage
#define glViewport                  glad_glViewport
#define glDrawArrays                glad_glDrawArrays
#define glDrawElements              glad_glDrawElements
#define glGenTextures               glad_glGenTextures
#define glDeleteTextures            glad_glDeleteTextures
#define glBindTexture               glad_glBindTexture
#define glActiveTexture             glad_glActiveTexture
#define glGenBuffers                glad_glGenBuffers
#define glDeleteBuffers             glad_glDeleteBuffers
#define glBindBuffer                glad_glBindBuffer
#define glBufferData                glad_glBufferData
#define glBufferSubData             glad_glBufferSubData
#define glGenVertexArrays           glad_glGenVertexArrays
#define glDeleteVertexArrays        glad_glDeleteVertexArrays
#define glBindVertexArray           glad_glBindVertexArray
#define glVertexAttribPointer       glad_glVertexAttribPointer
#define glEnableVertexAttribArray   glad_glEnableVertexAttribArray
#define glDisableVertexAttribArray  glad_glDisableVertexAttribArray
#define glCreateShader              glad_glCreateShader
#define glDeleteShader              glad_glDeleteShader
#define glShaderSource              glad_glShaderSource
#define glCompileShader             glad_glCompileShader
#define glGetShaderiv               glad_glGetShaderiv
#define glGetShaderInfoLog          glad_glGetShaderInfoLog
#define glCreateProgram             glad_glCreateProgram
#define glDeleteProgram             glad_glDeleteProgram
#define glAttachShader              glad_glAttachShader
#define glLinkProgram               glad_glLinkProgram
#define glGetProgramiv              glad_glGetProgramiv
#define glGetProgramInfoLog         glad_glGetProgramInfoLog
#define glUseProgram                glad_glUseProgram
#define glGetUniformLocation        glad_glGetUniformLocation
#define glUniform1i                 glad_glUniform1i
#define glUniform1f                 glad_glUniform1f
#define glUniform2f                 glad_glUniform2f
#define glUniform3f                 glad_glUniform3f
#define glUniform4f                 glad_glUniform4f
#define glUniformMatrix4fv          glad_glUniformMatrix4fv
#define glGenerateMipmap            glad_glGenerateMipmap
#define glGenFramebuffers           glad_glGenFramebuffers
#define glDeleteFramebuffers        glad_glDeleteFramebuffers
#define glBindFramebuffer           glad_glBindFramebuffer
#define glCheckFramebufferStatus    glad_glCheckFramebufferStatus
#define glFramebufferTexture2D      glad_glFramebufferTexture2D
#define glGenRenderbuffers          glad_glGenRenderbuffers
#define glDeleteRenderbuffers       glad_glDeleteRenderbuffers
#define glBindRenderbuffer          glad_glBindRenderbuffer
#define glRenderbufferStorage       glad_glRenderbufferStorage
#define glFramebufferRenderbuffer   glad_glFramebufferRenderbuffer
#define glTexImage2DMultisample     glad_glTexImage2DMultisample
#define glBlitFramebuffer           glad_glBlitFramebuffer
#define glGetStringi                glad_glGetStringi

typedef int (*GLADloadproc)(const char *name);
int gladLoadGLLoader(GLADloadproc load);

#ifdef __cplusplus
}
#endif

#endif /* __glad_h_ */
