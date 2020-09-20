/*
Copyright 2018 Ioannis Makris

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// This file was generated by glatter.py script.



#ifdef GLATTER_EGL
#if defined(__egl_h_)
#if defined(EGL_VERSION_1_0)
#ifndef eglChooseConfig_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglChooseConfig, (dpy, attrib_list, configs, config_size, num_config), (EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config))
#define eglChooseConfig_defined
#endif
#ifndef eglCopyBuffers_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCopyBuffers, (dpy, surface, target), (EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target))
#define eglCopyBuffers_defined
#endif
#ifndef eglCreateContext_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLContext, EGLAPIENTRY, eglCreateContext, (dpy, config, share_context, attrib_list), (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list))
#define eglCreateContext_defined
#endif
#ifndef eglCreatePbufferSurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePbufferSurface, (dpy, config, attrib_list), (EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list))
#define eglCreatePbufferSurface_defined
#endif
#ifndef eglCreatePixmapSurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePixmapSurface, (dpy, config, pixmap, attrib_list), (EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list))
#define eglCreatePixmapSurface_defined
#endif
#ifndef eglCreateWindowSurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreateWindowSurface, (dpy, config, win, attrib_list), (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list))
#define eglCreateWindowSurface_defined
#endif
#ifndef eglDestroyContext_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroyContext, (dpy, ctx), (EGLDisplay dpy, EGLContext ctx))
#define eglDestroyContext_defined
#endif
#ifndef eglDestroySurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroySurface, (dpy, surface), (EGLDisplay dpy, EGLSurface surface))
#define eglDestroySurface_defined
#endif
#ifndef eglGetConfigAttrib_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetConfigAttrib, (dpy, config, attribute, value), (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value))
#define eglGetConfigAttrib_defined
#endif
#ifndef eglGetConfigs_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetConfigs, (dpy, configs, config_size, num_config), (EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config))
#define eglGetConfigs_defined
#endif
#ifndef eglGetCurrentDisplay_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLDisplay, EGLAPIENTRY, eglGetCurrentDisplay, (), (void))
#define eglGetCurrentDisplay_defined
#endif
#ifndef eglGetCurrentSurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglGetCurrentSurface, (readdraw), (EGLint readdraw))
#define eglGetCurrentSurface_defined
#endif
#ifndef eglGetDisplay_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLDisplay, EGLAPIENTRY, eglGetDisplay, (display_id), (EGLNativeDisplayType display_id))
#define eglGetDisplay_defined
#endif
#ifndef eglGetError_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglGetError, (), (void))
#define eglGetError_defined
#endif
#ifndef eglGetProcAddress_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, __eglMustCastToProperFunctionPointerType, EGLAPIENTRY, eglGetProcAddress, (procname), (const char *procname))
#define eglGetProcAddress_defined
#endif
#ifndef eglInitialize_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglInitialize, (dpy, major, minor), (EGLDisplay dpy, EGLint *major, EGLint *minor))
#define eglInitialize_defined
#endif
#ifndef eglMakeCurrent_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglMakeCurrent, (dpy, draw, read, ctx), (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx))
#define eglMakeCurrent_defined
#endif
#ifndef eglQueryContext_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryContext, (dpy, ctx, attribute, value), (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value))
#define eglQueryContext_defined
#endif
#ifndef eglQueryString_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, const char *, EGLAPIENTRY, eglQueryString, (dpy, name), (EGLDisplay dpy, EGLint name))
#define eglQueryString_defined
#endif
#ifndef eglQuerySurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQuerySurface, (dpy, surface, attribute, value), (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value))
#define eglQuerySurface_defined
#endif
#ifndef eglSwapBuffers_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSwapBuffers, (dpy, surface), (EGLDisplay dpy, EGLSurface surface))
#define eglSwapBuffers_defined
#endif
#ifndef eglTerminate_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglTerminate, (dpy), (EGLDisplay dpy))
#define eglTerminate_defined
#endif
#ifndef eglWaitGL_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglWaitGL, (), (void))
#define eglWaitGL_defined
#endif
#ifndef eglWaitNative_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglWaitNative, (engine), (EGLint engine))
#define eglWaitNative_defined
#endif
#endif // defined(EGL_VERSION_1_0)
#if defined(EGL_VERSION_1_1)
#ifndef eglBindTexImage_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglBindTexImage, (dpy, surface, buffer), (EGLDisplay dpy, EGLSurface surface, EGLint buffer))
#define eglBindTexImage_defined
#endif
#ifndef eglReleaseTexImage_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglReleaseTexImage, (dpy, surface, buffer), (EGLDisplay dpy, EGLSurface surface, EGLint buffer))
#define eglReleaseTexImage_defined
#endif
#ifndef eglSurfaceAttrib_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSurfaceAttrib, (dpy, surface, attribute, value), (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value))
#define eglSurfaceAttrib_defined
#endif
#ifndef eglSwapInterval_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSwapInterval, (dpy, interval), (EGLDisplay dpy, EGLint interval))
#define eglSwapInterval_defined
#endif
#endif // defined(EGL_VERSION_1_1)
#if defined(EGL_VERSION_1_2)
#ifndef eglBindAPI_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglBindAPI, (api), (EGLenum api))
#define eglBindAPI_defined
#endif
#ifndef eglCreatePbufferFromClientBuffer_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePbufferFromClientBuffer, (dpy, buftype, buffer, config, attrib_list), (EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list))
#define eglCreatePbufferFromClientBuffer_defined
#endif
#ifndef eglQueryAPI_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLenum, EGLAPIENTRY, eglQueryAPI, (), (void))
#define eglQueryAPI_defined
#endif
#ifndef eglReleaseThread_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglReleaseThread, (), (void))
#define eglReleaseThread_defined
#endif
#ifndef eglWaitClient_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglWaitClient, (), (void))
#define eglWaitClient_defined
#endif
#endif // defined(EGL_VERSION_1_2)
#if defined(EGL_VERSION_1_4)
#ifndef eglGetCurrentContext_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLContext, EGLAPIENTRY, eglGetCurrentContext, (), (void))
#define eglGetCurrentContext_defined
#endif
#endif // defined(EGL_VERSION_1_4)
#if defined(EGL_VERSION_1_5)
#ifndef eglClientWaitSync_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglClientWaitSync, (dpy, sync, flags, timeout), (EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout))
#define eglClientWaitSync_defined
#endif
#ifndef eglCreateImage_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLImage, EGLAPIENTRY, eglCreateImage, (dpy, ctx, target, buffer, attrib_list), (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLAttrib *attrib_list))
#define eglCreateImage_defined
#endif
#ifndef eglCreatePlatformPixmapSurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePlatformPixmapSurface, (dpy, config, native_pixmap, attrib_list), (EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLAttrib *attrib_list))
#define eglCreatePlatformPixmapSurface_defined
#endif
#ifndef eglCreatePlatformWindowSurface_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePlatformWindowSurface, (dpy, config, native_window, attrib_list), (EGLDisplay dpy, EGLConfig config, void *native_window, const EGLAttrib *attrib_list))
#define eglCreatePlatformWindowSurface_defined
#endif
#ifndef eglCreateSync_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSync, EGLAPIENTRY, eglCreateSync, (dpy, type, attrib_list), (EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list))
#define eglCreateSync_defined
#endif
#ifndef eglDestroyImage_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroyImage, (dpy, image), (EGLDisplay dpy, EGLImage image))
#define eglDestroyImage_defined
#endif
#ifndef eglDestroySync_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroySync, (dpy, sync), (EGLDisplay dpy, EGLSync sync))
#define eglDestroySync_defined
#endif
#ifndef eglGetPlatformDisplay_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLDisplay, EGLAPIENTRY, eglGetPlatformDisplay, (platform, native_display, attrib_list), (EGLenum platform, void *native_display, const EGLAttrib *attrib_list))
#define eglGetPlatformDisplay_defined
#endif
#ifndef eglGetSyncAttrib_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetSyncAttrib, (dpy, sync, attribute, value), (EGLDisplay dpy, EGLSync sync, EGLint attribute, EGLAttrib *value))
#define eglGetSyncAttrib_defined
#endif
#ifndef eglWaitSync_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglWaitSync, (dpy, sync, flags), (EGLDisplay dpy, EGLSync sync, EGLint flags))
#define eglWaitSync_defined
#endif
#endif // defined(EGL_VERSION_1_5)
#endif // defined(__egl_h_)
#if defined(__eglext_h_)
#if defined(EGL_ANDROID_blob_cache)
#ifndef eglSetBlobCacheFuncsANDROID_defined
GLATTER_FBLOCK(, EGL, EGLAPI, void, EGLAPIENTRY, eglSetBlobCacheFuncsANDROID, (dpy, set, get), (EGLDisplay dpy, EGLSetBlobFuncANDROID set, EGLGetBlobFuncANDROID get))
#define eglSetBlobCacheFuncsANDROID_defined
#endif
#endif // defined(EGL_ANDROID_blob_cache)
#if defined(EGL_ANDROID_create_native_client_buffer)
#ifndef eglCreateNativeClientBufferANDROID_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLClientBuffer, EGLAPIENTRY, eglCreateNativeClientBufferANDROID, (attrib_list), (const EGLint *attrib_list))
#define eglCreateNativeClientBufferANDROID_defined
#endif
#endif // defined(EGL_ANDROID_create_native_client_buffer)
#if defined(EGL_ANDROID_native_fence_sync)
#ifndef eglDupNativeFenceFDANDROID_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglDupNativeFenceFDANDROID, (dpy, sync), (EGLDisplay dpy, EGLSyncKHR sync))
#define eglDupNativeFenceFDANDROID_defined
#endif
#endif // defined(EGL_ANDROID_native_fence_sync)
#if defined(EGL_ANDROID_presentation_time)
#ifndef eglPresentationTimeANDROID_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglPresentationTimeANDROID, (dpy, surface, time), (EGLDisplay dpy, EGLSurface surface, EGLnsecsANDROID time))
#define eglPresentationTimeANDROID_defined
#endif
#endif // defined(EGL_ANDROID_presentation_time)
#if defined(EGL_ANGLE_query_surface_pointer)
#ifndef eglQuerySurfacePointerANGLE_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQuerySurfacePointerANGLE, (dpy, surface, attribute, value), (EGLDisplay dpy, EGLSurface surface, EGLint attribute, void **value))
#define eglQuerySurfacePointerANGLE_defined
#endif
#endif // defined(EGL_ANGLE_query_surface_pointer)
#if defined(EGL_EXT_compositor)
#ifndef eglCompositorBindTexWindowEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorBindTexWindowEXT, (external_win_id), (EGLint external_win_id))
#define eglCompositorBindTexWindowEXT_defined
#endif
#ifndef eglCompositorSetContextAttributesEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorSetContextAttributesEXT, (external_ref_id, context_attributes, num_entries), (EGLint external_ref_id, const EGLint *context_attributes, EGLint num_entries))
#define eglCompositorSetContextAttributesEXT_defined
#endif
#ifndef eglCompositorSetContextListEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorSetContextListEXT, (external_ref_ids, num_entries), (const EGLint *external_ref_ids, EGLint num_entries))
#define eglCompositorSetContextListEXT_defined
#endif
#ifndef eglCompositorSetSizeEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorSetSizeEXT, (external_win_id, width, height), (EGLint external_win_id, EGLint width, EGLint height))
#define eglCompositorSetSizeEXT_defined
#endif
#ifndef eglCompositorSetWindowAttributesEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorSetWindowAttributesEXT, (external_win_id, window_attributes, num_entries), (EGLint external_win_id, const EGLint *window_attributes, EGLint num_entries))
#define eglCompositorSetWindowAttributesEXT_defined
#endif
#ifndef eglCompositorSetWindowListEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorSetWindowListEXT, (external_ref_id, external_win_ids, num_entries), (EGLint external_ref_id, const EGLint *external_win_ids, EGLint num_entries))
#define eglCompositorSetWindowListEXT_defined
#endif
#ifndef eglCompositorSwapPolicyEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglCompositorSwapPolicyEXT, (external_win_id, policy), (EGLint external_win_id, EGLint policy))
#define eglCompositorSwapPolicyEXT_defined
#endif
#endif // defined(EGL_EXT_compositor)
#if defined(EGL_EXT_device_base)
#ifndef eglQueryDeviceAttribEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDeviceAttribEXT, (device, attribute, value), (EGLDeviceEXT device, EGLint attribute, EGLAttrib *value))
#define eglQueryDeviceAttribEXT_defined
#endif
#ifndef eglQueryDeviceStringEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, const char *, EGLAPIENTRY, eglQueryDeviceStringEXT, (device, name), (EGLDeviceEXT device, EGLint name))
#define eglQueryDeviceStringEXT_defined
#endif
#ifndef eglQueryDevicesEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDevicesEXT, (max_devices, devices, num_devices), (EGLint max_devices, EGLDeviceEXT *devices, EGLint *num_devices))
#define eglQueryDevicesEXT_defined
#endif
#ifndef eglQueryDisplayAttribEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDisplayAttribEXT, (dpy, attribute, value), (EGLDisplay dpy, EGLint attribute, EGLAttrib *value))
#define eglQueryDisplayAttribEXT_defined
#endif
#endif // defined(EGL_EXT_device_base)
#if defined(EGL_EXT_image_dma_buf_import_modifiers)
#ifndef eglQueryDmaBufFormatsEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDmaBufFormatsEXT, (dpy, max_formats, formats, num_formats), (EGLDisplay dpy, EGLint max_formats, EGLint *formats, EGLint *num_formats))
#define eglQueryDmaBufFormatsEXT_defined
#endif
#ifndef eglQueryDmaBufModifiersEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDmaBufModifiersEXT, (dpy, format, max_modifiers, modifiers, external_only, num_modifiers), (EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR *modifiers, EGLBoolean *external_only, EGLint *num_modifiers))
#define eglQueryDmaBufModifiersEXT_defined
#endif
#endif // defined(EGL_EXT_image_dma_buf_import_modifiers)
#if defined(EGL_EXT_output_base)
#ifndef eglGetOutputLayersEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetOutputLayersEXT, (dpy, attrib_list, layers, max_layers, num_layers), (EGLDisplay dpy, const EGLAttrib *attrib_list, EGLOutputLayerEXT *layers, EGLint max_layers, EGLint *num_layers))
#define eglGetOutputLayersEXT_defined
#endif
#ifndef eglGetOutputPortsEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetOutputPortsEXT, (dpy, attrib_list, ports, max_ports, num_ports), (EGLDisplay dpy, const EGLAttrib *attrib_list, EGLOutputPortEXT *ports, EGLint max_ports, EGLint *num_ports))
#define eglGetOutputPortsEXT_defined
#endif
#ifndef eglOutputLayerAttribEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglOutputLayerAttribEXT, (dpy, layer, attribute, value), (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib value))
#define eglOutputLayerAttribEXT_defined
#endif
#ifndef eglOutputPortAttribEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglOutputPortAttribEXT, (dpy, port, attribute, value), (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib value))
#define eglOutputPortAttribEXT_defined
#endif
#ifndef eglQueryOutputLayerAttribEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryOutputLayerAttribEXT, (dpy, layer, attribute, value), (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib *value))
#define eglQueryOutputLayerAttribEXT_defined
#endif
#ifndef eglQueryOutputLayerStringEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, const char *, EGLAPIENTRY, eglQueryOutputLayerStringEXT, (dpy, layer, name), (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint name))
#define eglQueryOutputLayerStringEXT_defined
#endif
#ifndef eglQueryOutputPortAttribEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryOutputPortAttribEXT, (dpy, port, attribute, value), (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib *value))
#define eglQueryOutputPortAttribEXT_defined
#endif
#ifndef eglQueryOutputPortStringEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, const char *, EGLAPIENTRY, eglQueryOutputPortStringEXT, (dpy, port, name), (EGLDisplay dpy, EGLOutputPortEXT port, EGLint name))
#define eglQueryOutputPortStringEXT_defined
#endif
#endif // defined(EGL_EXT_output_base)
#if defined(EGL_EXT_platform_base)
#ifndef eglCreatePlatformPixmapSurfaceEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePlatformPixmapSurfaceEXT, (dpy, config, native_pixmap, attrib_list), (EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list))
#define eglCreatePlatformPixmapSurfaceEXT_defined
#endif
#ifndef eglCreatePlatformWindowSurfaceEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePlatformWindowSurfaceEXT, (dpy, config, native_window, attrib_list), (EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list))
#define eglCreatePlatformWindowSurfaceEXT_defined
#endif
#ifndef eglGetPlatformDisplayEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLDisplay, EGLAPIENTRY, eglGetPlatformDisplayEXT, (platform, native_display, attrib_list), (EGLenum platform, void *native_display, const EGLint *attrib_list))
#define eglGetPlatformDisplayEXT_defined
#endif
#endif // defined(EGL_EXT_platform_base)
#if defined(EGL_EXT_stream_consumer_egloutput)
#ifndef eglStreamConsumerOutputEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerOutputEXT, (dpy, stream, layer), (EGLDisplay dpy, EGLStreamKHR stream, EGLOutputLayerEXT layer))
#define eglStreamConsumerOutputEXT_defined
#endif
#endif // defined(EGL_EXT_stream_consumer_egloutput)
#if defined(EGL_EXT_swap_buffers_with_damage)
#ifndef eglSwapBuffersWithDamageEXT_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSwapBuffersWithDamageEXT, (dpy, surface, rects, n_rects), (EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects))
#define eglSwapBuffersWithDamageEXT_defined
#endif
#endif // defined(EGL_EXT_swap_buffers_with_damage)
#if defined(EGL_HI_clientpixmap)
#ifndef eglCreatePixmapSurfaceHI_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreatePixmapSurfaceHI, (dpy, config, pixmap), (EGLDisplay dpy, EGLConfig config, struct EGLClientPixmapHI *pixmap))
#define eglCreatePixmapSurfaceHI_defined
#endif
#endif // defined(EGL_HI_clientpixmap)
#if defined(EGL_KHR_cl_event2)
#ifndef eglCreateSync64KHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSyncKHR, EGLAPIENTRY, eglCreateSync64KHR, (dpy, type, attrib_list), (EGLDisplay dpy, EGLenum type, const EGLAttribKHR *attrib_list))
#define eglCreateSync64KHR_defined
#endif
#endif // defined(EGL_KHR_cl_event2)
#if defined(EGL_KHR_debug)
#ifndef eglDebugMessageControlKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglDebugMessageControlKHR, (callback, attrib_list), (EGLDEBUGPROCKHR callback, const EGLAttrib *attrib_list))
#define eglDebugMessageControlKHR_defined
#endif
#ifndef eglLabelObjectKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglLabelObjectKHR, (display, objectType, object, label), (EGLDisplay display, EGLenum objectType, EGLObjectKHR object, EGLLabelKHR label))
#define eglLabelObjectKHR_defined
#endif
#ifndef eglQueryDebugKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDebugKHR, (attribute, value), (EGLint attribute, EGLAttrib *value))
#define eglQueryDebugKHR_defined
#endif
#endif // defined(EGL_KHR_debug)
#if defined(EGL_KHR_fence_sync)
#if defined(KHRONOS_SUPPORT_INT64)
#ifndef eglClientWaitSyncKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglClientWaitSyncKHR, (dpy, sync, flags, timeout), (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags, EGLTimeKHR timeout))
#define eglClientWaitSyncKHR_defined
#endif
#ifndef eglCreateSyncKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSyncKHR, EGLAPIENTRY, eglCreateSyncKHR, (dpy, type, attrib_list), (EGLDisplay dpy, EGLenum type, const EGLint *attrib_list))
#define eglCreateSyncKHR_defined
#endif
#ifndef eglDestroySyncKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroySyncKHR, (dpy, sync), (EGLDisplay dpy, EGLSyncKHR sync))
#define eglDestroySyncKHR_defined
#endif
#ifndef eglGetSyncAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetSyncAttribKHR, (dpy, sync, attribute, value), (EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint *value))
#define eglGetSyncAttribKHR_defined
#endif
#endif // defined(KHRONOS_SUPPORT_INT64)
#endif // defined(EGL_KHR_fence_sync)
#if defined(EGL_KHR_image)
#ifndef eglCreateImageKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLImageKHR, EGLAPIENTRY, eglCreateImageKHR, (dpy, ctx, target, buffer, attrib_list), (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list))
#define eglCreateImageKHR_defined
#endif
#ifndef eglDestroyImageKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroyImageKHR, (dpy, image), (EGLDisplay dpy, EGLImageKHR image))
#define eglDestroyImageKHR_defined
#endif
#endif // defined(EGL_KHR_image)
#if defined(EGL_KHR_lock_surface)
#ifndef eglLockSurfaceKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglLockSurfaceKHR, (dpy, surface, attrib_list), (EGLDisplay dpy, EGLSurface surface, const EGLint *attrib_list))
#define eglLockSurfaceKHR_defined
#endif
#ifndef eglUnlockSurfaceKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglUnlockSurfaceKHR, (dpy, surface), (EGLDisplay dpy, EGLSurface surface))
#define eglUnlockSurfaceKHR_defined
#endif
#endif // defined(EGL_KHR_lock_surface)
#if defined(EGL_KHR_lock_surface3)
#ifndef eglQuerySurface64KHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQuerySurface64KHR, (dpy, surface, attribute, value), (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLAttribKHR *value))
#define eglQuerySurface64KHR_defined
#endif
#endif // defined(EGL_KHR_lock_surface3)
#if defined(EGL_KHR_partial_update)
#ifndef eglSetDamageRegionKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSetDamageRegionKHR, (dpy, surface, rects, n_rects), (EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects))
#define eglSetDamageRegionKHR_defined
#endif
#endif // defined(EGL_KHR_partial_update)
#if defined(EGL_KHR_reusable_sync)
#if defined(KHRONOS_SUPPORT_INT64)
#ifndef eglSignalSyncKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSignalSyncKHR, (dpy, sync, mode), (EGLDisplay dpy, EGLSyncKHR sync, EGLenum mode))
#define eglSignalSyncKHR_defined
#endif
#endif // defined(KHRONOS_SUPPORT_INT64)
#endif // defined(EGL_KHR_reusable_sync)
#if defined(EGL_KHR_stream)
#if defined(KHRONOS_SUPPORT_INT64)
#ifndef eglCreateStreamKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLStreamKHR, EGLAPIENTRY, eglCreateStreamKHR, (dpy, attrib_list), (EGLDisplay dpy, const EGLint *attrib_list))
#define eglCreateStreamKHR_defined
#endif
#ifndef eglDestroyStreamKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroyStreamKHR, (dpy, stream), (EGLDisplay dpy, EGLStreamKHR stream))
#define eglDestroyStreamKHR_defined
#endif
#ifndef eglQueryStreamKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryStreamKHR, (dpy, stream, attribute, value), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint *value))
#define eglQueryStreamKHR_defined
#endif
#ifndef eglQueryStreamu64KHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryStreamu64KHR, (dpy, stream, attribute, value), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLuint64KHR *value))
#define eglQueryStreamu64KHR_defined
#endif
#ifndef eglStreamAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamAttribKHR, (dpy, stream, attribute, value), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint value))
#define eglStreamAttribKHR_defined
#endif
#endif // defined(KHRONOS_SUPPORT_INT64)
#endif // defined(EGL_KHR_stream)
#if defined(EGL_KHR_stream_attrib)
#if defined(KHRONOS_SUPPORT_INT64)
#ifndef eglCreateStreamAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLStreamKHR, EGLAPIENTRY, eglCreateStreamAttribKHR, (dpy, attrib_list), (EGLDisplay dpy, const EGLAttrib *attrib_list))
#define eglCreateStreamAttribKHR_defined
#endif
#ifndef eglQueryStreamAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryStreamAttribKHR, (dpy, stream, attribute, value), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLAttrib *value))
#define eglQueryStreamAttribKHR_defined
#endif
#ifndef eglSetStreamAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSetStreamAttribKHR, (dpy, stream, attribute, value), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLAttrib value))
#define eglSetStreamAttribKHR_defined
#endif
#ifndef eglStreamConsumerAcquireAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerAcquireAttribKHR, (dpy, stream, attrib_list), (EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib *attrib_list))
#define eglStreamConsumerAcquireAttribKHR_defined
#endif
#ifndef eglStreamConsumerReleaseAttribKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerReleaseAttribKHR, (dpy, stream, attrib_list), (EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib *attrib_list))
#define eglStreamConsumerReleaseAttribKHR_defined
#endif
#endif // defined(KHRONOS_SUPPORT_INT64)
#endif // defined(EGL_KHR_stream_attrib)
#if defined(EGL_KHR_stream_consumer_gltexture)
#if defined(EGL_KHR_stream)
#ifndef eglStreamConsumerAcquireKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerAcquireKHR, (dpy, stream), (EGLDisplay dpy, EGLStreamKHR stream))
#define eglStreamConsumerAcquireKHR_defined
#endif
#ifndef eglStreamConsumerGLTextureExternalKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerGLTextureExternalKHR, (dpy, stream), (EGLDisplay dpy, EGLStreamKHR stream))
#define eglStreamConsumerGLTextureExternalKHR_defined
#endif
#ifndef eglStreamConsumerReleaseKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerReleaseKHR, (dpy, stream), (EGLDisplay dpy, EGLStreamKHR stream))
#define eglStreamConsumerReleaseKHR_defined
#endif
#endif // defined(EGL_KHR_stream)
#endif // defined(EGL_KHR_stream_consumer_gltexture)
#if defined(EGL_KHR_stream_cross_process_fd)
#if defined(EGL_KHR_stream)
#ifndef eglCreateStreamFromFileDescriptorKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLStreamKHR, EGLAPIENTRY, eglCreateStreamFromFileDescriptorKHR, (dpy, file_descriptor), (EGLDisplay dpy, EGLNativeFileDescriptorKHR file_descriptor))
#define eglCreateStreamFromFileDescriptorKHR_defined
#endif
#ifndef eglGetStreamFileDescriptorKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLNativeFileDescriptorKHR, EGLAPIENTRY, eglGetStreamFileDescriptorKHR, (dpy, stream), (EGLDisplay dpy, EGLStreamKHR stream))
#define eglGetStreamFileDescriptorKHR_defined
#endif
#endif // defined(EGL_KHR_stream)
#endif // defined(EGL_KHR_stream_cross_process_fd)
#if defined(EGL_KHR_stream_fifo)
#if defined(EGL_KHR_stream)
#ifndef eglQueryStreamTimeKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryStreamTimeKHR, (dpy, stream, attribute, value), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR *value))
#define eglQueryStreamTimeKHR_defined
#endif
#endif // defined(EGL_KHR_stream)
#endif // defined(EGL_KHR_stream_fifo)
#if defined(EGL_KHR_stream_producer_eglsurface)
#if defined(EGL_KHR_stream)
#ifndef eglCreateStreamProducerSurfaceKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSurface, EGLAPIENTRY, eglCreateStreamProducerSurfaceKHR, (dpy, config, stream, attrib_list), (EGLDisplay dpy, EGLConfig config, EGLStreamKHR stream, const EGLint *attrib_list))
#define eglCreateStreamProducerSurfaceKHR_defined
#endif
#endif // defined(EGL_KHR_stream)
#endif // defined(EGL_KHR_stream_producer_eglsurface)
#if defined(EGL_KHR_swap_buffers_with_damage)
#ifndef eglSwapBuffersWithDamageKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSwapBuffersWithDamageKHR, (dpy, surface, rects, n_rects), (EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects))
#define eglSwapBuffersWithDamageKHR_defined
#endif
#endif // defined(EGL_KHR_swap_buffers_with_damage)
#if defined(EGL_KHR_wait_sync)
#ifndef eglWaitSyncKHR_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglWaitSyncKHR, (dpy, sync, flags), (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags))
#define eglWaitSyncKHR_defined
#endif
#endif // defined(EGL_KHR_wait_sync)
#if defined(EGL_MESA_drm_image)
#ifndef eglCreateDRMImageMESA_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLImageKHR, EGLAPIENTRY, eglCreateDRMImageMESA, (dpy, attrib_list), (EGLDisplay dpy, const EGLint *attrib_list))
#define eglCreateDRMImageMESA_defined
#endif
#ifndef eglExportDRMImageMESA_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglExportDRMImageMESA, (dpy, image, name, handle, stride), (EGLDisplay dpy, EGLImageKHR image, EGLint *name, EGLint *handle, EGLint *stride))
#define eglExportDRMImageMESA_defined
#endif
#endif // defined(EGL_MESA_drm_image)
#if defined(EGL_MESA_image_dma_buf_export)
#ifndef eglExportDMABUFImageMESA_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglExportDMABUFImageMESA, (dpy, image, fds, strides, offsets), (EGLDisplay dpy, EGLImageKHR image, int *fds, EGLint *strides, EGLint *offsets))
#define eglExportDMABUFImageMESA_defined
#endif
#ifndef eglExportDMABUFImageQueryMESA_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglExportDMABUFImageQueryMESA, (dpy, image, fourcc, num_planes, modifiers), (EGLDisplay dpy, EGLImageKHR image, int *fourcc, int *num_planes, EGLuint64KHR *modifiers))
#define eglExportDMABUFImageQueryMESA_defined
#endif
#endif // defined(EGL_MESA_image_dma_buf_export)
#if defined(EGL_NOK_swap_region)
#ifndef eglSwapBuffersRegionNOK_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSwapBuffersRegionNOK, (dpy, surface, numRects, rects), (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint *rects))
#define eglSwapBuffersRegionNOK_defined
#endif
#endif // defined(EGL_NOK_swap_region)
#if defined(EGL_NOK_swap_region2)
#ifndef eglSwapBuffersRegion2NOK_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSwapBuffersRegion2NOK, (dpy, surface, numRects, rects), (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint *rects))
#define eglSwapBuffersRegion2NOK_defined
#endif
#endif // defined(EGL_NOK_swap_region2)
#if defined(EGL_NV_native_query)
#ifndef eglQueryNativeDisplayNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryNativeDisplayNV, (dpy, display_id), (EGLDisplay dpy, EGLNativeDisplayType *display_id))
#define eglQueryNativeDisplayNV_defined
#endif
#ifndef eglQueryNativePixmapNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryNativePixmapNV, (dpy, surf, pixmap), (EGLDisplay dpy, EGLSurface surf, EGLNativePixmapType *pixmap))
#define eglQueryNativePixmapNV_defined
#endif
#ifndef eglQueryNativeWindowNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryNativeWindowNV, (dpy, surf, window), (EGLDisplay dpy, EGLSurface surf, EGLNativeWindowType *window))
#define eglQueryNativeWindowNV_defined
#endif
#endif // defined(EGL_NV_native_query)
#if defined(EGL_NV_post_sub_buffer)
#ifndef eglPostSubBufferNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglPostSubBufferNV, (dpy, surface, x, y, width, height), (EGLDisplay dpy, EGLSurface surface, EGLint x, EGLint y, EGLint width, EGLint height))
#define eglPostSubBufferNV_defined
#endif
#endif // defined(EGL_NV_post_sub_buffer)
#if defined(EGL_NV_stream_consumer_gltexture_yuv)
#ifndef eglStreamConsumerGLTextureExternalAttribsNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglStreamConsumerGLTextureExternalAttribsNV, (dpy, stream, attrib_list), (EGLDisplay dpy, EGLStreamKHR stream, EGLAttrib *attrib_list))
#define eglStreamConsumerGLTextureExternalAttribsNV_defined
#endif
#endif // defined(EGL_NV_stream_consumer_gltexture_yuv)
#if defined(EGL_NV_stream_metadata)
#ifndef eglQueryDisplayAttribNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryDisplayAttribNV, (dpy, attribute, value), (EGLDisplay dpy, EGLint attribute, EGLAttrib *value))
#define eglQueryDisplayAttribNV_defined
#endif
#ifndef eglQueryStreamMetadataNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglQueryStreamMetadataNV, (dpy, stream, name, n, offset, size, data), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum name, EGLint n, EGLint offset, EGLint size, void *data))
#define eglQueryStreamMetadataNV_defined
#endif
#ifndef eglSetStreamMetadataNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSetStreamMetadataNV, (dpy, stream, n, offset, size, data), (EGLDisplay dpy, EGLStreamKHR stream, EGLint n, EGLint offset, EGLint size, const void *data))
#define eglSetStreamMetadataNV_defined
#endif
#endif // defined(EGL_NV_stream_metadata)
#if defined(EGL_NV_stream_reset)
#ifndef eglResetStreamNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglResetStreamNV, (dpy, stream), (EGLDisplay dpy, EGLStreamKHR stream))
#define eglResetStreamNV_defined
#endif
#endif // defined(EGL_NV_stream_reset)
#if defined(EGL_NV_stream_sync)
#ifndef eglCreateStreamSyncNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSyncKHR, EGLAPIENTRY, eglCreateStreamSyncNV, (dpy, stream, type, attrib_list), (EGLDisplay dpy, EGLStreamKHR stream, EGLenum type, const EGLint *attrib_list))
#define eglCreateStreamSyncNV_defined
#endif
#endif // defined(EGL_NV_stream_sync)
#if defined(EGL_NV_sync)
#if defined(KHRONOS_SUPPORT_INT64)
#ifndef eglClientWaitSyncNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLint, EGLAPIENTRY, eglClientWaitSyncNV, (sync, flags, timeout), (EGLSyncNV sync, EGLint flags, EGLTimeNV timeout))
#define eglClientWaitSyncNV_defined
#endif
#ifndef eglCreateFenceSyncNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLSyncNV, EGLAPIENTRY, eglCreateFenceSyncNV, (dpy, condition, attrib_list), (EGLDisplay dpy, EGLenum condition, const EGLint *attrib_list))
#define eglCreateFenceSyncNV_defined
#endif
#ifndef eglDestroySyncNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglDestroySyncNV, (sync), (EGLSyncNV sync))
#define eglDestroySyncNV_defined
#endif
#ifndef eglFenceNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglFenceNV, (sync), (EGLSyncNV sync))
#define eglFenceNV_defined
#endif
#ifndef eglGetSyncAttribNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglGetSyncAttribNV, (sync, attribute, value), (EGLSyncNV sync, EGLint attribute, EGLint *value))
#define eglGetSyncAttribNV_defined
#endif
#ifndef eglSignalSyncNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLBoolean, EGLAPIENTRY, eglSignalSyncNV, (sync, mode), (EGLSyncNV sync, EGLenum mode))
#define eglSignalSyncNV_defined
#endif
#endif // defined(KHRONOS_SUPPORT_INT64)
#endif // defined(EGL_NV_sync)
#if defined(EGL_NV_system_time)
#if defined(KHRONOS_SUPPORT_INT64)
#ifndef eglGetSystemTimeFrequencyNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLuint64NV, EGLAPIENTRY, eglGetSystemTimeFrequencyNV, (), (void))
#define eglGetSystemTimeFrequencyNV_defined
#endif
#ifndef eglGetSystemTimeNV_defined
GLATTER_FBLOCK(return, EGL, EGLAPI, EGLuint64NV, EGLAPIENTRY, eglGetSystemTimeNV, (), (void))
#define eglGetSystemTimeNV_defined
#endif
#endif // defined(__eglext_h_)
#endif // defined(EGL_NV_system_time)
#endif // defined(KHRONOS_SUPPORT_INT64)
#endif // GLATTER_EGL

