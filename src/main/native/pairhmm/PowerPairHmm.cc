#include <vector>
#include <math.h>
#include <debug.h>
#include <assert.h>
#include "Context.h"
#include "JavaData.h"

JNIEXPORT void JNICALL Java_com_ibm_pairhmm_PowerPairHmm_initNative
(JNIEnv* env, jclass cls, jclass readDataHolder, jclass haplotypeDataHolder,
 jboolean use_double, jint max_threads)
{
  DBG("Enter");

  DBG("Exit");
  return;
}

JNIEXPORT void JNICALL Java_com_ibm_pairhmm_PowerPairHmm_computeLikelihoodsNative
(JNIEnv* env, jobject obj,
 jobjectArray readDataArray, jobjectArray haplotypeDataArray, jdoubleArray likelihoodArray)
{
  DBG("Enter");

  DBG("Exit");
  return;
}

JNIEXPORT void JNICALL Java_com_ibm_pairhmm_PowerPairHmm_doneNative
(JNIEnv* env, jobject obj)
{
  DBG("Enter");

  DBG("Exit");
  return;
}
