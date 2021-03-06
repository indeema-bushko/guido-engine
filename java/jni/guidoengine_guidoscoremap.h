/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class guidoengine_guidoscoremap */

#ifndef _Included_guidoengine_guidoscoremap
#define _Included_guidoengine_guidoscoremap
#ifdef __cplusplus
extern "C" {
#endif
#undef guidoengine_guidoscoremap_kGuidoPage
#define guidoengine_guidoscoremap_kGuidoPage 0L
#undef guidoengine_guidoscoremap_kGuidoSystem
#define guidoengine_guidoscoremap_kGuidoSystem 1L
#undef guidoengine_guidoscoremap_kGuidoSystemSlice
#define guidoengine_guidoscoremap_kGuidoSystemSlice 2L
#undef guidoengine_guidoscoremap_kGuidoStaff
#define guidoengine_guidoscoremap_kGuidoStaff 3L
#undef guidoengine_guidoscoremap_kGuidoBar
#define guidoengine_guidoscoremap_kGuidoBar 4L
#undef guidoengine_guidoscoremap_kGuidoEvent
#define guidoengine_guidoscoremap_kGuidoEvent 5L
/*
 * Class:     guidoengine_guidoscoremap
 * Method:    disposeNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_guidoengine_guidoscoremap_disposeNative
  (JNIEnv *, jobject);

/*
 * Class:     guidoengine_guidoscoremap
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guidoscoremap_size
  (JNIEnv *, jobject);

/*
 * Class:     guidoengine_guidoscoremap
 * Method:    get
 * Signature: (ILguidoengine/guidosegment;Ljava/awt/Rectangle;)Z
 */
JNIEXPORT jboolean JNICALL Java_guidoengine_guidoscoremap_get
  (JNIEnv *, jobject, jint, jobject, jobject);

/*
 * Class:     guidoengine_guidoscoremap
 * Method:    getTime
 * Signature: (Lguidoengine/guidodate;Lguidoengine/guidosegment;Ljava/awt/Rectangle;)Z
 */
JNIEXPORT jboolean JNICALL Java_guidoengine_guidoscoremap_getTime
  (JNIEnv *, jobject, jobject, jobject, jobject);

/*
 * Class:     guidoengine_guidoscoremap
 * Method:    getPoint
 * Signature: (FFLguidoengine/guidosegment;Ljava/awt/Rectangle;)Z
 */
JNIEXPORT jboolean JNICALL Java_guidoengine_guidoscoremap_getPoint
  (JNIEnv *, jobject, jfloat, jfloat, jobject, jobject);

/*
 * Class:     guidoengine_guidoscoremap
 * Method:    Init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_guidoengine_guidoscoremap_Init
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
