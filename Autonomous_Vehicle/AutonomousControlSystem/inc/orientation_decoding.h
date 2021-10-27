 /******************************************************************************
 *
 * File Name:   orientation_decoding.h
 *
 * Description: Header file for utility functions and definitions
 *              Related to orientation and steering
 *
 * Date:        10/12/2020
 *
 ******************************************************************************/

#ifndef ORIENT_STEER_UTILS_H
#define ORIENT_STEER_UTILS_H

#include <stdint.h>
/*******************************************************************************
 *                           Preprocessor Definies                             *
 *******************************************************************************/
/* steering Configurations */
#define STEERING_STEP 0.45f
#define ORIENT_TO_STEERING_PARAM 3.5f
#define WRAP_AROUND_CORRECTION_FACTOR 360.0f

/* These Values are Tested Physically. Date: 22/11/2020 */
#define MAX_ORIENTATION 26
#define MIN_ORIENTATION -24
#define MAX_ORIENTATION_2 24
#define MIN_ORIENTATION_2 -26

/*Orientation related defines*/
#define POSITIVE_TO_NEGATIVE_WRAP_AROUND    1
#define NEGATIVE_TO_POSITIVE_WRAP_AROUND    2

typedef int8_t WRAP_AROUND_FLAG;


/*******************************************************************************
 *                                 Macros                                    *
 *******************************************************************************/
/*Checks if passed angle is a positive angle ranging between 0 to 180 degrees*/
#define CHECK_POSITIVE_ANGLE(ANGLE) (ANGLE>=0 && ANGLE<=180)

/*Checks if passed angle is a negative angle ranging between -180 to 0*/
#define CHECK_NEGATIVE_ANGLE(ANGLE) (ANGLE>-180 && ANGLE<0)


/*******************************************************************************
 *                          Functions Prototypes                               *
 *******************************************************************************/
WRAP_AROUND_FLAG int8_getOrientationWrapAroundFlag(float a_currentOrientation, float a_desiredOrienatation);
void v_adjustDesiredOrientaion(WRAP_AROUND_FLAG a_wrapAroundFlag, float currentOrientation, float * a_desiredOrientationPtr);
long f_DecodeOrientationIntoSteering (float a_desiredOrientation);
long f_DecodeResetOrientation (float a_desiredOrientation);

#endif /*ORIENT_STEER_UTILS_H*/
