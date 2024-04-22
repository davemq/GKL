#include <vector>
#include <math.h>
#include <debug.h>
#include <assert.h>
#include <jni.h>
#include "pairhmm_common.h"
#include "Context.h"
#include "JavaData.h"

/*
 * Class:     com_ibm_pairhmm_PowerPairHmm
 * Method:    initNative
 * Signature: (Ljava/lang/Class;Ljava/lang/Class;ZI)V
 */
JNIEXPORT void JNICALL Java_com_ibm_pairhmm_PowerPairHmm_initNative
(JNIEnv* env, jclass cls, jclass readDataHolder, jclass haplotypeDataHolder,
 jboolean use_double, jint max_threads)
{
  DBG("Enter");

  JavaData javaData(env);
  try {
    javaData.init(readDataHolder, haplotypeDataHolder);
  } catch (JavaException& e) {
    env->ExceptionClear();
    env->ThrowNew(env->FindClass(e.classPath), e.message);
    return;
  }

  if (max_threads != 1) {
    DBG("Ignoring request for %d threads; not using OpenMP implementation", max_threads);
  }

  DBG("Exit");
  return;
}

/*
 * Class:     com_ibm_pairhmm_PowerPairHmm
 * Method:    computeLikelihoodsNative
 * Signature: ([Ljava/lang/Object;[Ljava/lang/Object;[D)V
 */
JNIEXPORT void JNICALL Java_com_ibm_pairhmm_PowerPairHmm_computeLikelihoodsNative
(JNIEnv* env, jobject obj,
 jobjectArray readDataArray, jobjectArray haplotypeDataArray, jdoubleArray likelihoodArray)
{
  DBG("Enter");

  DBG("Exit");
  return;
}

/*
 * Class:     com_ibm_pairhmm_PowerPairHmm
 * Method:    doneNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ibm_pairhmm_PowerPairHmm_doneNative
(JNIEnv* env, jobject obj)
{
  DBG("Enter");

  DBG("Exit");
  return;
}
