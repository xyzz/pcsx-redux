/***************************************************************************
 *   Copyright (C) 2020 PCSX-Redux authors                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.           *
 ***************************************************************************/

#include "lua/glffi.h"

#include <GL/gl3w.h>

#include "lua/luawrapper.h"

template <typename T, size_t S>
static void registerSymbol(PCSX::Lua L, const char (&name)[S], const T ptr) {
    L.push<S>(name);
    L.push((void*)ptr);
    L.settable();
}

#define REGISTER(L, s) registerSymbol(L, #s, s)

static void registerAllSymbols(PCSX::Lua L) {
    L.push("_CLIBS");
    L.gettable(LUA_REGISTRYINDEX);
    if (L.isnil()) {
        L.pop();
        L.newtable();
        L.push("_CLIBS");
        L.copy(-2);
        L.settable(LUA_REGISTRYINDEX);
    }
    L.push("gl");
    L.newtable();
    REGISTER(L, glCullFace);
    REGISTER(L, glFrontFace);
    REGISTER(L, glHint);
    REGISTER(L, glLineWidth);
    REGISTER(L, glPointSize);
    REGISTER(L, glPolygonMode);
    REGISTER(L, glScissor);
    REGISTER(L, glTexParameterf);
    REGISTER(L, glTexParameterfv);
    REGISTER(L, glTexParameteri);
    REGISTER(L, glTexParameteriv);
    REGISTER(L, glTexImage1D);
    REGISTER(L, glTexImage2D);
    REGISTER(L, glDrawBuffer);
    REGISTER(L, glClear);
    REGISTER(L, glClearColor);
    REGISTER(L, glClearStencil);
    REGISTER(L, glClearDepth);
    REGISTER(L, glStencilMask);
    REGISTER(L, glColorMask);
    REGISTER(L, glDepthMask);
    REGISTER(L, glDisable);
    REGISTER(L, glEnable);
    REGISTER(L, glFinish);
    REGISTER(L, glFlush);
    REGISTER(L, glBlendFunc);
    REGISTER(L, glLogicOp);
    REGISTER(L, glStencilFunc);
    REGISTER(L, glStencilOp);
    REGISTER(L, glDepthFunc);
    REGISTER(L, glPixelStoref);
    REGISTER(L, glPixelStorei);
    REGISTER(L, glReadBuffer);
    REGISTER(L, glReadPixels);
    REGISTER(L, glGetBooleanv);
    REGISTER(L, glGetDoublev);
    REGISTER(L, glGetError);
    REGISTER(L, glGetFloatv);
    REGISTER(L, glGetIntegerv);
    REGISTER(L, glGetString);
    REGISTER(L, glGetTexImage);
    REGISTER(L, glGetTexParameterfv);
    REGISTER(L, glGetTexParameteriv);
    REGISTER(L, glGetTexLevelParameterfv);
    REGISTER(L, glGetTexLevelParameteriv);
    REGISTER(L, glIsEnabled);
    REGISTER(L, glDepthRange);
    REGISTER(L, glViewport);
    REGISTER(L, glDrawArrays);
    REGISTER(L, glDrawElements);
    REGISTER(L, glGetPointerv);
    REGISTER(L, glPolygonOffset);
    REGISTER(L, glCopyTexImage1D);
    REGISTER(L, glCopyTexImage2D);
    REGISTER(L, glCopyTexSubImage1D);
    REGISTER(L, glCopyTexSubImage2D);
    REGISTER(L, glTexSubImage1D);
    REGISTER(L, glTexSubImage2D);
    REGISTER(L, glBindTexture);
    REGISTER(L, glDeleteTextures);
    REGISTER(L, glGenTextures);
    REGISTER(L, glIsTexture);
    REGISTER(L, glBlendColor);
    REGISTER(L, glBlendEquation);
    REGISTER(L, glDrawRangeElements);
    REGISTER(L, glTexImage3D);
    REGISTER(L, glTexSubImage3D);
    REGISTER(L, glCopyTexSubImage3D);
    REGISTER(L, glActiveTexture);
    REGISTER(L, glSampleCoverage);
    REGISTER(L, glCompressedTexImage3D);
    REGISTER(L, glCompressedTexImage2D);
    REGISTER(L, glCompressedTexImage1D);
    REGISTER(L, glCompressedTexSubImage3D);
    REGISTER(L, glCompressedTexSubImage2D);
    REGISTER(L, glCompressedTexSubImage1D);
    REGISTER(L, glGetCompressedTexImage);
    REGISTER(L, glBlendFuncSeparate);
    REGISTER(L, glMultiDrawArrays);
    REGISTER(L, glMultiDrawElements);
    REGISTER(L, glPointParameterf);
    REGISTER(L, glPointParameterfv);
    REGISTER(L, glPointParameteri);
    REGISTER(L, glPointParameteriv);
    REGISTER(L, glGenQueries);
    REGISTER(L, glDeleteQueries);
    REGISTER(L, glIsQuery);
    REGISTER(L, glBeginQuery);
    REGISTER(L, glEndQuery);
    REGISTER(L, glGetQueryiv);
    REGISTER(L, glGetQueryObjectiv);
    REGISTER(L, glGetQueryObjectuiv);
    REGISTER(L, glBindBuffer);
    REGISTER(L, glDeleteBuffers);
    REGISTER(L, glGenBuffers);
    REGISTER(L, glIsBuffer);
    REGISTER(L, glBufferData);
    REGISTER(L, glBufferSubData);
    REGISTER(L, glGetBufferSubData);
    REGISTER(L, glMapBuffer);
    REGISTER(L, glUnmapBuffer);
    REGISTER(L, glGetBufferParameteriv);
    REGISTER(L, glGetBufferPointerv);
    REGISTER(L, glBlendEquationSeparate);
    REGISTER(L, glDrawBuffers);
    REGISTER(L, glStencilOpSeparate);
    REGISTER(L, glStencilFuncSeparate);
    REGISTER(L, glStencilMaskSeparate);
    REGISTER(L, glAttachShader);
    REGISTER(L, glBindAttribLocation);
    REGISTER(L, glCompileShader);
    REGISTER(L, glCreateProgram);
    REGISTER(L, glCreateShader);
    REGISTER(L, glDeleteProgram);
    REGISTER(L, glDeleteShader);
    REGISTER(L, glDetachShader);
    REGISTER(L, glDisableVertexAttribArray);
    REGISTER(L, glEnableVertexAttribArray);
    REGISTER(L, glGetActiveAttrib);
    REGISTER(L, glGetActiveUniform);
    REGISTER(L, glGetAttachedShaders);
    REGISTER(L, glGetAttribLocation);
    REGISTER(L, glGetProgramiv);
    REGISTER(L, glGetProgramInfoLog);
    REGISTER(L, glGetShaderiv);
    REGISTER(L, glGetShaderInfoLog);
    REGISTER(L, glGetShaderSource);
    REGISTER(L, glGetUniformLocation);
    REGISTER(L, glGetUniformfv);
    REGISTER(L, glGetUniformiv);
    REGISTER(L, glGetVertexAttribdv);
    REGISTER(L, glGetVertexAttribfv);
    REGISTER(L, glGetVertexAttribiv);
    REGISTER(L, glGetVertexAttribPointerv);
    REGISTER(L, glIsProgram);
    REGISTER(L, glIsShader);
    REGISTER(L, glLinkProgram);
    REGISTER(L, glShaderSource);
    REGISTER(L, glUseProgram);
    REGISTER(L, glUniform1f);
    REGISTER(L, glUniform2f);
    REGISTER(L, glUniform3f);
    REGISTER(L, glUniform4f);
    REGISTER(L, glUniform1i);
    REGISTER(L, glUniform2i);
    REGISTER(L, glUniform3i);
    REGISTER(L, glUniform4i);
    REGISTER(L, glUniform1fv);
    REGISTER(L, glUniform2fv);
    REGISTER(L, glUniform3fv);
    REGISTER(L, glUniform4fv);
    REGISTER(L, glUniform1iv);
    REGISTER(L, glUniform2iv);
    REGISTER(L, glUniform3iv);
    REGISTER(L, glUniform4iv);
    REGISTER(L, glUniformMatrix2fv);
    REGISTER(L, glUniformMatrix3fv);
    REGISTER(L, glUniformMatrix4fv);
    REGISTER(L, glValidateProgram);
    REGISTER(L, glVertexAttrib1d);
    REGISTER(L, glVertexAttrib1dv);
    REGISTER(L, glVertexAttrib1f);
    REGISTER(L, glVertexAttrib1fv);
    REGISTER(L, glVertexAttrib1s);
    REGISTER(L, glVertexAttrib1sv);
    REGISTER(L, glVertexAttrib2d);
    REGISTER(L, glVertexAttrib2dv);
    REGISTER(L, glVertexAttrib2f);
    REGISTER(L, glVertexAttrib2fv);
    REGISTER(L, glVertexAttrib2s);
    REGISTER(L, glVertexAttrib2sv);
    REGISTER(L, glVertexAttrib3d);
    REGISTER(L, glVertexAttrib3dv);
    REGISTER(L, glVertexAttrib3f);
    REGISTER(L, glVertexAttrib3fv);
    REGISTER(L, glVertexAttrib3s);
    REGISTER(L, glVertexAttrib3sv);
    REGISTER(L, glVertexAttrib4Nbv);
    REGISTER(L, glVertexAttrib4Niv);
    REGISTER(L, glVertexAttrib4Nsv);
    REGISTER(L, glVertexAttrib4Nub);
    REGISTER(L, glVertexAttrib4Nubv);
    REGISTER(L, glVertexAttrib4Nuiv);
    REGISTER(L, glVertexAttrib4Nusv);
    REGISTER(L, glVertexAttrib4bv);
    REGISTER(L, glVertexAttrib4d);
    REGISTER(L, glVertexAttrib4dv);
    REGISTER(L, glVertexAttrib4f);
    REGISTER(L, glVertexAttrib4fv);
    REGISTER(L, glVertexAttrib4iv);
    REGISTER(L, glVertexAttrib4s);
    REGISTER(L, glVertexAttrib4sv);
    REGISTER(L, glVertexAttrib4ubv);
    REGISTER(L, glVertexAttrib4uiv);
    REGISTER(L, glVertexAttrib4usv);
    REGISTER(L, glVertexAttribPointer);
    REGISTER(L, glUniformMatrix2x3fv);
    REGISTER(L, glUniformMatrix3x2fv);
    REGISTER(L, glUniformMatrix2x4fv);
    REGISTER(L, glUniformMatrix4x2fv);
    REGISTER(L, glUniformMatrix3x4fv);
    REGISTER(L, glUniformMatrix4x3fv);
    REGISTER(L, glColorMaski);
    REGISTER(L, glGetBooleani_v);
    REGISTER(L, glGetIntegeri_v);
    REGISTER(L, glEnablei);
    REGISTER(L, glDisablei);
    REGISTER(L, glIsEnabledi);
    REGISTER(L, glBeginTransformFeedback);
    REGISTER(L, glEndTransformFeedback);
    REGISTER(L, glBindBufferRange);
    REGISTER(L, glBindBufferBase);
    REGISTER(L, glTransformFeedbackVaryings);
    REGISTER(L, glGetTransformFeedbackVarying);
    REGISTER(L, glClampColor);
    REGISTER(L, glBeginConditionalRender);
    REGISTER(L, glEndConditionalRender);
    REGISTER(L, glVertexAttribIPointer);
    REGISTER(L, glGetVertexAttribIiv);
    REGISTER(L, glGetVertexAttribIuiv);
    REGISTER(L, glVertexAttribI1i);
    REGISTER(L, glVertexAttribI2i);
    REGISTER(L, glVertexAttribI3i);
    REGISTER(L, glVertexAttribI4i);
    REGISTER(L, glVertexAttribI1ui);
    REGISTER(L, glVertexAttribI2ui);
    REGISTER(L, glVertexAttribI3ui);
    REGISTER(L, glVertexAttribI4ui);
    REGISTER(L, glVertexAttribI1iv);
    REGISTER(L, glVertexAttribI2iv);
    REGISTER(L, glVertexAttribI3iv);
    REGISTER(L, glVertexAttribI4iv);
    REGISTER(L, glVertexAttribI1uiv);
    REGISTER(L, glVertexAttribI2uiv);
    REGISTER(L, glVertexAttribI3uiv);
    REGISTER(L, glVertexAttribI4uiv);
    REGISTER(L, glVertexAttribI4bv);
    REGISTER(L, glVertexAttribI4sv);
    REGISTER(L, glVertexAttribI4ubv);
    REGISTER(L, glVertexAttribI4usv);
    REGISTER(L, glGetUniformuiv);
    REGISTER(L, glBindFragDataLocation);
    REGISTER(L, glGetFragDataLocation);
    REGISTER(L, glUniform1ui);
    REGISTER(L, glUniform2ui);
    REGISTER(L, glUniform3ui);
    REGISTER(L, glUniform4ui);
    REGISTER(L, glUniform1uiv);
    REGISTER(L, glUniform2uiv);
    REGISTER(L, glUniform3uiv);
    REGISTER(L, glUniform4uiv);
    REGISTER(L, glTexParameterIiv);
    REGISTER(L, glTexParameterIuiv);
    REGISTER(L, glGetTexParameterIiv);
    REGISTER(L, glGetTexParameterIuiv);
    REGISTER(L, glClearBufferiv);
    REGISTER(L, glClearBufferuiv);
    REGISTER(L, glClearBufferfv);
    REGISTER(L, glClearBufferfi);
    REGISTER(L, glGetStringi);
    REGISTER(L, glDrawArraysInstanced);
    REGISTER(L, glDrawElementsInstanced);
    REGISTER(L, glTexBuffer);
    REGISTER(L, glPrimitiveRestartIndex);
    REGISTER(L, glGetInteger64i_v);
    REGISTER(L, glGetBufferParameteri64v);
    REGISTER(L, glFramebufferTexture);
    REGISTER(L, glVertexAttribDivisor);
    REGISTER(L, glMinSampleShading);
    REGISTER(L, glBlendEquationi);
    REGISTER(L, glBlendEquationSeparatei);
    REGISTER(L, glBlendFunci);
    REGISTER(L, glBlendFuncSeparatei);
    REGISTER(L, glIsRenderbuffer);
    REGISTER(L, glBindRenderbuffer);
    REGISTER(L, glDeleteRenderbuffers);
    REGISTER(L, glGenRenderbuffers);
    REGISTER(L, glRenderbufferStorage);
    REGISTER(L, glGetRenderbufferParameteriv);
    REGISTER(L, glIsFramebuffer);
    REGISTER(L, glBindFramebuffer);
    REGISTER(L, glDeleteFramebuffers);
    REGISTER(L, glGenFramebuffers);
    REGISTER(L, glCheckFramebufferStatus);
    REGISTER(L, glFramebufferTexture1D);
    REGISTER(L, glFramebufferTexture2D);
    REGISTER(L, glFramebufferTexture3D);
    REGISTER(L, glFramebufferRenderbuffer);
    REGISTER(L, glGetFramebufferAttachmentParameteriv);
    REGISTER(L, glGenerateMipmap);
    REGISTER(L, glBlitFramebuffer);
    REGISTER(L, glRenderbufferStorageMultisample);
    REGISTER(L, glFramebufferTextureLayer);
    REGISTER(L, glMapBufferRange);
    REGISTER(L, glFlushMappedBufferRange);
    REGISTER(L, glBindVertexArray);
    REGISTER(L, glDeleteVertexArrays);
    REGISTER(L, glGenVertexArrays);
    REGISTER(L, glIsVertexArray);
    REGISTER(L, glGetUniformIndices);
    REGISTER(L, glGetActiveUniformsiv);
    REGISTER(L, glGetActiveUniformName);
    REGISTER(L, glGetUniformBlockIndex);
    REGISTER(L, glGetActiveUniformBlockiv);
    REGISTER(L, glGetActiveUniformBlockName);
    REGISTER(L, glUniformBlockBinding);
    REGISTER(L, glCopyBufferSubData);
    REGISTER(L, glDrawElementsBaseVertex);
    REGISTER(L, glDrawRangeElementsBaseVertex);
    REGISTER(L, glDrawElementsInstancedBaseVertex);
    REGISTER(L, glMultiDrawElementsBaseVertex);
    REGISTER(L, glProvokingVertex);
    REGISTER(L, glFenceSync);
    REGISTER(L, glIsSync);
    REGISTER(L, glDeleteSync);
    REGISTER(L, glClientWaitSync);
    REGISTER(L, glWaitSync);
    REGISTER(L, glGetInteger64v);
    REGISTER(L, glGetSynciv);
    REGISTER(L, glTexImage2DMultisample);
    REGISTER(L, glTexImage3DMultisample);
    REGISTER(L, glGetMultisamplefv);
    REGISTER(L, glSampleMaski);
    REGISTER(L, glBlendEquationiARB);
    REGISTER(L, glBlendEquationSeparateiARB);
    REGISTER(L, glBlendFunciARB);
    REGISTER(L, glBlendFuncSeparateiARB);
    REGISTER(L, glMinSampleShadingARB);
    REGISTER(L, glNamedStringARB);
    REGISTER(L, glDeleteNamedStringARB);
    REGISTER(L, glCompileShaderIncludeARB);
    REGISTER(L, glIsNamedStringARB);
    REGISTER(L, glGetNamedStringARB);
    REGISTER(L, glGetNamedStringivARB);
    REGISTER(L, glBindFragDataLocationIndexed);
    REGISTER(L, glGetFragDataIndex);
    REGISTER(L, glGenSamplers);
    REGISTER(L, glDeleteSamplers);
    REGISTER(L, glIsSampler);
    REGISTER(L, glBindSampler);
    REGISTER(L, glSamplerParameteri);
    REGISTER(L, glSamplerParameteriv);
    REGISTER(L, glSamplerParameterf);
    REGISTER(L, glSamplerParameterfv);
    REGISTER(L, glSamplerParameterIiv);
    REGISTER(L, glSamplerParameterIuiv);
    REGISTER(L, glGetSamplerParameteriv);
    REGISTER(L, glGetSamplerParameterIiv);
    REGISTER(L, glGetSamplerParameterfv);
    REGISTER(L, glGetSamplerParameterIuiv);
    REGISTER(L, glQueryCounter);
    REGISTER(L, glGetQueryObjecti64v);
    REGISTER(L, glGetQueryObjectui64v);
    REGISTER(L, glVertexP2ui);
    REGISTER(L, glVertexP2uiv);
    REGISTER(L, glVertexP3ui);
    REGISTER(L, glVertexP3uiv);
    REGISTER(L, glVertexP4ui);
    REGISTER(L, glVertexP4uiv);
    REGISTER(L, glTexCoordP1ui);
    REGISTER(L, glTexCoordP1uiv);
    REGISTER(L, glTexCoordP2ui);
    REGISTER(L, glTexCoordP2uiv);
    REGISTER(L, glTexCoordP3ui);
    REGISTER(L, glTexCoordP3uiv);
    REGISTER(L, glTexCoordP4ui);
    REGISTER(L, glTexCoordP4uiv);
    REGISTER(L, glMultiTexCoordP1ui);
    REGISTER(L, glMultiTexCoordP1uiv);
    REGISTER(L, glMultiTexCoordP2ui);
    REGISTER(L, glMultiTexCoordP2uiv);
    REGISTER(L, glMultiTexCoordP3ui);
    REGISTER(L, glMultiTexCoordP3uiv);
    REGISTER(L, glMultiTexCoordP4ui);
    REGISTER(L, glMultiTexCoordP4uiv);
    REGISTER(L, glNormalP3ui);
    REGISTER(L, glNormalP3uiv);
    REGISTER(L, glColorP3ui);
    REGISTER(L, glColorP3uiv);
    REGISTER(L, glColorP4ui);
    REGISTER(L, glColorP4uiv);
    REGISTER(L, glSecondaryColorP3ui);
    REGISTER(L, glSecondaryColorP3uiv);
    REGISTER(L, glVertexAttribP1ui);
    REGISTER(L, glVertexAttribP1uiv);
    REGISTER(L, glVertexAttribP2ui);
    REGISTER(L, glVertexAttribP2uiv);
    REGISTER(L, glVertexAttribP3ui);
    REGISTER(L, glVertexAttribP3uiv);
    REGISTER(L, glVertexAttribP4ui);
    REGISTER(L, glVertexAttribP4uiv);
    REGISTER(L, glDrawArraysIndirect);
    REGISTER(L, glDrawElementsIndirect);
    REGISTER(L, glUniform1d);
    REGISTER(L, glUniform2d);
    REGISTER(L, glUniform3d);
    REGISTER(L, glUniform4d);
    REGISTER(L, glUniform1dv);
    REGISTER(L, glUniform2dv);
    REGISTER(L, glUniform3dv);
    REGISTER(L, glUniform4dv);
    REGISTER(L, glUniformMatrix2dv);
    REGISTER(L, glUniformMatrix3dv);
    REGISTER(L, glUniformMatrix4dv);
    REGISTER(L, glUniformMatrix2x3dv);
    REGISTER(L, glUniformMatrix2x4dv);
    REGISTER(L, glUniformMatrix3x2dv);
    REGISTER(L, glUniformMatrix3x4dv);
    REGISTER(L, glUniformMatrix4x2dv);
    REGISTER(L, glUniformMatrix4x3dv);
    REGISTER(L, glGetUniformdv);
    REGISTER(L, glGetSubroutineUniformLocation);
    REGISTER(L, glGetSubroutineIndex);
    REGISTER(L, glGetActiveSubroutineUniformiv);
    REGISTER(L, glGetActiveSubroutineUniformName);
    REGISTER(L, glGetActiveSubroutineName);
    REGISTER(L, glUniformSubroutinesuiv);
    REGISTER(L, glGetUniformSubroutineuiv);
    REGISTER(L, glGetProgramStageiv);
    REGISTER(L, glPatchParameteri);
    REGISTER(L, glPatchParameterfv);
    REGISTER(L, glBindTransformFeedback);
    REGISTER(L, glDeleteTransformFeedbacks);
    REGISTER(L, glGenTransformFeedbacks);
    REGISTER(L, glIsTransformFeedback);
    REGISTER(L, glPauseTransformFeedback);
    REGISTER(L, glResumeTransformFeedback);
    REGISTER(L, glDrawTransformFeedback);
    REGISTER(L, glDrawTransformFeedbackStream);
    REGISTER(L, glBeginQueryIndexed);
    REGISTER(L, glEndQueryIndexed);
    REGISTER(L, glGetQueryIndexediv);
    REGISTER(L, glReleaseShaderCompiler);
    REGISTER(L, glShaderBinary);
    REGISTER(L, glGetShaderPrecisionFormat);
    REGISTER(L, glDepthRangef);
    REGISTER(L, glClearDepthf);
    REGISTER(L, glGetProgramBinary);
    REGISTER(L, glProgramBinary);
    REGISTER(L, glProgramParameteri);
    REGISTER(L, glUseProgramStages);
    REGISTER(L, glActiveShaderProgram);
    REGISTER(L, glCreateShaderProgramv);
    REGISTER(L, glBindProgramPipeline);
    REGISTER(L, glDeleteProgramPipelines);
    REGISTER(L, glGenProgramPipelines);
    REGISTER(L, glIsProgramPipeline);
    REGISTER(L, glGetProgramPipelineiv);
    REGISTER(L, glProgramUniform1i);
    REGISTER(L, glProgramUniform1iv);
    REGISTER(L, glProgramUniform1f);
    REGISTER(L, glProgramUniform1fv);
    REGISTER(L, glProgramUniform1d);
    REGISTER(L, glProgramUniform1dv);
    REGISTER(L, glProgramUniform1ui);
    REGISTER(L, glProgramUniform1uiv);
    REGISTER(L, glProgramUniform2i);
    REGISTER(L, glProgramUniform2iv);
    REGISTER(L, glProgramUniform2f);
    REGISTER(L, glProgramUniform2fv);
    REGISTER(L, glProgramUniform2d);
    REGISTER(L, glProgramUniform2dv);
    REGISTER(L, glProgramUniform2ui);
    REGISTER(L, glProgramUniform2uiv);
    REGISTER(L, glProgramUniform3i);
    REGISTER(L, glProgramUniform3iv);
    REGISTER(L, glProgramUniform3f);
    REGISTER(L, glProgramUniform3fv);
    REGISTER(L, glProgramUniform3d);
    REGISTER(L, glProgramUniform3dv);
    REGISTER(L, glProgramUniform3ui);
    REGISTER(L, glProgramUniform3uiv);
    REGISTER(L, glProgramUniform4i);
    REGISTER(L, glProgramUniform4iv);
    REGISTER(L, glProgramUniform4f);
    REGISTER(L, glProgramUniform4fv);
    REGISTER(L, glProgramUniform4d);
    REGISTER(L, glProgramUniform4dv);
    REGISTER(L, glProgramUniform4ui);
    REGISTER(L, glProgramUniform4uiv);
    REGISTER(L, glProgramUniformMatrix2fv);
    REGISTER(L, glProgramUniformMatrix3fv);
    REGISTER(L, glProgramUniformMatrix4fv);
    REGISTER(L, glProgramUniformMatrix2dv);
    REGISTER(L, glProgramUniformMatrix3dv);
    REGISTER(L, glProgramUniformMatrix4dv);
    REGISTER(L, glProgramUniformMatrix2x3fv);
    REGISTER(L, glProgramUniformMatrix3x2fv);
    REGISTER(L, glProgramUniformMatrix2x4fv);
    REGISTER(L, glProgramUniformMatrix4x2fv);
    REGISTER(L, glProgramUniformMatrix3x4fv);
    REGISTER(L, glProgramUniformMatrix4x3fv);
    REGISTER(L, glProgramUniformMatrix2x3dv);
    REGISTER(L, glProgramUniformMatrix3x2dv);
    REGISTER(L, glProgramUniformMatrix2x4dv);
    REGISTER(L, glProgramUniformMatrix4x2dv);
    REGISTER(L, glProgramUniformMatrix3x4dv);
    REGISTER(L, glProgramUniformMatrix4x3dv);
    REGISTER(L, glValidateProgramPipeline);
    REGISTER(L, glGetProgramPipelineInfoLog);
    REGISTER(L, glVertexAttribL1d);
    REGISTER(L, glVertexAttribL2d);
    REGISTER(L, glVertexAttribL3d);
    REGISTER(L, glVertexAttribL4d);
    REGISTER(L, glVertexAttribL1dv);
    REGISTER(L, glVertexAttribL2dv);
    REGISTER(L, glVertexAttribL3dv);
    REGISTER(L, glVertexAttribL4dv);
    REGISTER(L, glVertexAttribLPointer);
    REGISTER(L, glGetVertexAttribLdv);
    REGISTER(L, glViewportArrayv);
    REGISTER(L, glViewportIndexedf);
    REGISTER(L, glViewportIndexedfv);
    REGISTER(L, glScissorArrayv);
    REGISTER(L, glScissorIndexed);
    REGISTER(L, glScissorIndexedv);
    REGISTER(L, glDepthRangeArrayv);
    REGISTER(L, glDepthRangeIndexed);
    REGISTER(L, glGetFloati_v);
    REGISTER(L, glGetDoublei_v);
    REGISTER(L, glCreateSyncFromCLeventARB);
    REGISTER(L, glDebugMessageControlARB);
    REGISTER(L, glDebugMessageInsertARB);
    REGISTER(L, glDebugMessageCallbackARB);
    REGISTER(L, glGetDebugMessageLogARB);
    REGISTER(L, glGetGraphicsResetStatusARB);
    REGISTER(L, glGetnTexImageARB);
    REGISTER(L, glReadnPixelsARB);
    REGISTER(L, glGetnCompressedTexImageARB);
    REGISTER(L, glGetnUniformfvARB);
    REGISTER(L, glGetnUniformivARB);
    REGISTER(L, glGetnUniformuivARB);
    REGISTER(L, glGetnUniformdvARB);
    REGISTER(L, glDrawArraysInstancedBaseInstance);
    REGISTER(L, glDrawElementsInstancedBaseInstance);
    REGISTER(L, glDrawElementsInstancedBaseVertexBaseInstance);
    REGISTER(L, glDrawTransformFeedbackInstanced);
    REGISTER(L, glDrawTransformFeedbackStreamInstanced);
    REGISTER(L, glGetInternalformativ);
    REGISTER(L, glGetActiveAtomicCounterBufferiv);
    REGISTER(L, glBindImageTexture);
    REGISTER(L, glMemoryBarrier);
    REGISTER(L, glTexStorage1D);
    REGISTER(L, glTexStorage2D);
    REGISTER(L, glTexStorage3D);
    REGISTER(L, glTextureStorage1DEXT);
    REGISTER(L, glTextureStorage2DEXT);
    REGISTER(L, glTextureStorage3DEXT);
    REGISTER(L, glDebugMessageControl);
    REGISTER(L, glDebugMessageInsert);
    REGISTER(L, glDebugMessageCallback);
    REGISTER(L, glGetDebugMessageLog);
    REGISTER(L, glPushDebugGroup);
    REGISTER(L, glPopDebugGroup);
    REGISTER(L, glObjectLabel);
    REGISTER(L, glGetObjectLabel);
    REGISTER(L, glObjectPtrLabel);
    REGISTER(L, glGetObjectPtrLabel);
    REGISTER(L, glClearBufferData);
    REGISTER(L, glClearBufferSubData);
    REGISTER(L, glClearNamedBufferDataEXT);
    REGISTER(L, glClearNamedBufferSubDataEXT);
    REGISTER(L, glDispatchCompute);
    REGISTER(L, glDispatchComputeIndirect);
    REGISTER(L, glCopyImageSubData);
    REGISTER(L, glTextureView);
    REGISTER(L, glBindVertexBuffer);
    REGISTER(L, glVertexAttribFormat);
    REGISTER(L, glVertexAttribIFormat);
    REGISTER(L, glVertexAttribLFormat);
    REGISTER(L, glVertexAttribBinding);
    REGISTER(L, glVertexBindingDivisor);
    REGISTER(L, glVertexArrayBindVertexBufferEXT);
    REGISTER(L, glVertexArrayVertexAttribFormatEXT);
    REGISTER(L, glVertexArrayVertexAttribIFormatEXT);
    REGISTER(L, glVertexArrayVertexAttribLFormatEXT);
    REGISTER(L, glVertexArrayVertexAttribBindingEXT);
    REGISTER(L, glVertexArrayVertexBindingDivisorEXT);
    REGISTER(L, glFramebufferParameteri);
    REGISTER(L, glGetFramebufferParameteriv);
    REGISTER(L, glNamedFramebufferParameteriEXT);
    REGISTER(L, glGetNamedFramebufferParameterivEXT);
    REGISTER(L, glGetInternalformati64v);
    REGISTER(L, glInvalidateTexSubImage);
    REGISTER(L, glInvalidateTexImage);
    REGISTER(L, glInvalidateBufferSubData);
    REGISTER(L, glInvalidateBufferData);
    REGISTER(L, glInvalidateFramebuffer);
    REGISTER(L, glInvalidateSubFramebuffer);
    REGISTER(L, glMultiDrawArraysIndirect);
    REGISTER(L, glMultiDrawElementsIndirect);
    REGISTER(L, glGetProgramInterfaceiv);
    REGISTER(L, glGetProgramResourceIndex);
    REGISTER(L, glGetProgramResourceName);
    REGISTER(L, glGetProgramResourceiv);
    REGISTER(L, glGetProgramResourceLocation);
    REGISTER(L, glGetProgramResourceLocationIndex);
    REGISTER(L, glShaderStorageBlockBinding);
    REGISTER(L, glTexBufferRange);
    REGISTER(L, glTextureBufferRangeEXT);
    REGISTER(L, glTexStorage2DMultisample);
    REGISTER(L, glTexStorage3DMultisample);
    REGISTER(L, glTextureStorage2DMultisampleEXT);
    REGISTER(L, glTextureStorage3DMultisampleEXT);
    L.settable();
    L.pop();
}

void PCSX::LuaFFI::open_gl(Lua L) {
    registerAllSymbols(L);
    static int lualoader = 8;
    static const char* glFFI_enum1 = (
#include "third_party/glffi/glffi-enum1.lua"
    );
    static const char* glFFI_enum2 = (
#include "third_party/glffi/glffi-enum2.lua"
    );
    static const char* glFFI_enum3 = (
#include "third_party/glffi/glffi-enum3.lua"
    );
    static const char* glFFI_typedefs = (
#include "third_party/glffi/glffi-typedefs.lua"
    );
    static const char* glFFI_def1 = (
#include "third_party/glffi/glffi-def1.lua"
    );
    static const char* glFFI_def2 = (
#include "third_party/glffi/glffi-def2.lua"
    );
    static const char* glFFI_def3 = (
#include "third_party/glffi/glffi-def3.lua"
    );
    static const char* glFFI_def4 = (
#include "third_party/glffi/glffi-def4.lua"
    );
    L.load(glFFI_enum1, "internal:third_party/glffi/glffi-enum1.lua");
    L.load(glFFI_enum2, "internal:third_party/glffi/glffi-enum2.lua");
    L.load(glFFI_enum3, "internal:third_party/glffi/glffi-enum3.lua");
    L.load(glFFI_typedefs, "internal:third_party/glffi/glffi-typedefs.lua");
    L.load(glFFI_def1, "internal:third_party/glffi/glffi-def1.lua");
    L.load(glFFI_def2, "internal:third_party/glffi/glffi-def2.lua");
    L.load(glFFI_def3, "internal:third_party/glffi/glffi-def3.lua");
    L.load(glFFI_def4, "internal:third_party/glffi/glffi-def4.lua");
}