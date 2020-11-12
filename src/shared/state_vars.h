/*
 * Project Sakura - Akeno
 * Copyright (C) 2020 Glenn Toews
 * This software is licensed under the LGPLv3 license
 */

/**
 * @file state_vars.h
 * @author Glenn Toews
 * @date 11 Nov 2020
 * @brief This file defines globally shared variables for the powertrain
 *        control unit.
 */

#include "stdint.h"
#include "stdbool.h"
#include "constants.h"

/**
 * @brief Data types
 */
enum type_eng_running_state
{
    STOPPED = 0,
    STOPPED_PREPPING = 1,
    STOPPED_AUTOSTOP = 2,
    STOPPED_DIED = 4,
    RUNNING_IDLE_FREE = 5,
    RUNNING_IDLE_DRIVING = 6,
    RUNNING_NORMAL = 7,
    RUNNING_HARD_LIMITER = 8,
    RUNNING_SOFT_LIMITER = 9,
    RUNNING_IGNITION_CUT = 10,
    RUNNING_FUEL_CUT = 11,
    RUNNING_COMPLETE_CUT = 12,
    RUNNING_LAUNCH_PREP = 13,
    RUNNING_LAUNCH_LIMIT = 14,
    RUNNING_LAUNCH_START = 15
};

enum type_eng_emergency_state
{
    NORMAL = 0,
    POWER_LIFT_1 = 1,
    POWER_LIFT_2 = 2,
    EMERGENCY = 3
};

enum type_eng_performance_state
{
    WET = 0,
    NORM = 1,
    SPORT = 2,
    RACE_COOL = 3,
    RACE_NORM = 4,
    RACE_FAST = 5,
    RACE_SPRINT = 6
};

enum type_eng_fuel_state
{
    OFF = 0,
    ON = 1
};

enum type_eng_injector_state
{
    CLOSED = 0,
    OPEN = 1
};

enum type_eng_ignition_state
{
    OFF = 0,
    ON = 1
};

enum type_eng_ignition_coil_state
{
    OFF = 0,
    ON = 1
};

enum type_eng_vtec_solenoid_state
{
    OFF = 0,
    ON = 1
};

enum type_trans_gear_type
{
    REVERSE = 0,
    NEUTRAL = 1,
    D_1 = 2,
    D_2 = 3,
    D_3 = 4,
    D_4 = 5,
    D_5 = 6,
    D_6 = 7,
    D_7 = 8,
    D_8 = 9
};

enum type_trans_mode_type
{
    REVERSE = 0,
    NEUTRAL = 1,
    DRIVE_AUTO = 2,
    DRIVE_MANUAL = 3
};

enum type_trans_shift_state_type
{
    NEUTRAL = 0,
    IN_GEAR = 1,
    DISENGAGING_GEAR = 2,
    ENGAGING_GEAR = 3
};

enum type_trans_clutch_state_type
{
    DISENGAGED = 0,
    FULL_ENGAGED = 1,
    SHIFT_SLIP = 2,
    LAUNCH_SLIP = 3,
    UNCONTROLLED_SLIP = 4
};

enum type_driver_brake_pressed
{
    DEPRESSED = 0,
    PRESSED = 1
};

enum type_driver_parking_brake_engaged
{
    DISENGAGED = 0,
    ENGAGED = 1
};

/**
 * @brief Engine state variables
 */
volatile type_eng_running_state eng_running_state = type_eng_running_state::STOPPED;
volatile type_eng_emergency_state eng_emergency_state = type_eng_emergency_state::NORMAL;
volatile type_eng_performance_state eng_performance_state = type_eng_performance_state::NORM;

/**
 * @brief Speed variables
 */
volatile uint32_t eng_crank_speed = 0; // unit: rpm

volatile uint32_t eng_turbo_left_speed = 0;  // unit: rpm
volatile uint32_t eng_turbo_right_speed = 0; // unit: rpm

volatile uint32_t trans_inshaft_speed = 0;  // unit: rpm
volatile uint32_t trans_outshaft_speed = 0; // unit: rpm

/**
 * @brief Position variables
 */
volatile uint32_t eng_crank_pos = 0;     // unit: 1/10 °
volatile uint32_t eng_cam_left_pos = 0;  // unit: 1/10 °
volatile uint32_t eng_cam_right_pos = 0; // unit: 1/10 °

/**
 * @brief Temp variables
 */
volatile uint32_t eng_coolant_in_temp = 0;  // unit: °C * 10
volatile uint32_t eng_coolant_out_temp = 0; // unit: °C * 10

volatile uint32_t eng_ic_water_in_temp = 0;  // unit: °C * 10
volatile uint32_t eng_ic_water_out_temp = 0; // unit: °C * 10

volatile uint32_t eng_oil_tank_temp = 0; // unit: °C * 10
volatile uint32_t eng_oil_sump_temp = 0; // unit: °C * 10

volatile uint32_t eng_intake_left_pre_turbo_temp = 0; // unit: °C * 10
volatile uint32_t eng_intake_left_pre_ic_temp = 0;    // unit: °C * 10
volatile uint32_t eng_intake_left_post_ic_temp = 0;   // unit: °C * 10

volatile uint32_t eng_intake_right_pre_turbo_temp = 0; // unit: °C * 10
volatile uint32_t eng_intake_right_pre_ic_temp = 0;    // unit: °C * 10
volatile uint32_t eng_intake_right_post_ic_temp = 0;   // unit: °C * 10

volatile uint32_t eng_intake_manifold_temp = 0; // unit: °C * 10

volatile uint32_t eng_exhaust_left_1_temp = 0; // unit: °C * 10
volatile uint32_t eng_exhaust_left_2_temp = 0; // unit: °C * 10

volatile uint32_t eng_exhaust_right_1_temp = 0; // unit: °C * 10
volatile uint32_t eng_exhaust_right_2_temp = 0; // unit: °C * 10

volatile uint32_t trans_oil_temp = 0; // unit: °C * 10

/**
 * @brief Pressure variables
 */
volatile uint32_t eng_water_in_pres = 0; // unit: mbar

volatile uint32_t eng_oil_in_pres = 0; // unit: mbar

volatile uint32_t eng_turbo_left_oil_in_pres = 0; // unit: mbar

volatile uint32_t eng_turbo_right_oil_in_pres = 0; // unit: mbar

volatile uint32_t eng_intake_left_pre_turbo_pres = 0; // unit: mbar

volatile uint32_t eng_intake_right_pre_turbo_pres = 0; // unit: mbar

volatile uint32_t eng_intake_manifold_pres_cmd = 0; // unit: mbar
volatile uint32_t eng_intake_manifold_pres = 0;     // unit: mbar

volatile uint32_t eng_intake_cyl_left_pres_cmd = 0;  // unit: mbar
volatile uint32_t eng_intake_cyl_right_pres_cmd = 0; // unit: mbar

volatile uint32_t eng_fuel_rail_pres = 0; // unit: mbar

/**
 * @brief Throttle variables
 */
volatile uint32_t eng_throttle_left_cmd = 0; // unit: 1/10 %
volatile uint32_t eng_throttle_left = 0;     // unit: 1/10 %

volatile uint32_t eng_throttle_right_cmd = 0; // unit: 1/10 %
volatile uint32_t eng_throttle_right = 0;     // unit: 1/10 %

/**
 * @brief Lambda variables
 */
volatile uint32_t eng_exhaust_left_lambda_cmd = 0;      // unit: 100 * lambda
volatile uint32_t eng_exhaust_left_lambda = 0;          // unit: 100 * lambda
volatile uint32_t eng_exhaust_left_post_cat_lambda = 0; // unit: 100 * lambda

volatile uint32_t eng_exhaust_right_lambda_cmd = 0;      // unit: 100 * lambda
volatile uint32_t eng_exhaust_right_lambda = 0;          // unit: 100 * lambda
volatile uint32_t eng_exhaust_right_post_cat_lambda = 0; // unit: 100 * lambda

/**
 * @brief Knock control variables
 */
volatile uint32_t eng_knock_left_level = 0;  // unit: 1/10 %
volatile uint32_t eng_knock_right_level = 0; // unit: 1/10 %

volatile uint32_t eng_knock_left_ignition_retard_cmd = 0;  // unit: 1/10 °
volatile uint32_t eng_knock_right_ignition_retard_cmd = 0; // unit: 1/10 °

volatile uint32_t eng_knock_intake_cyl_left_pres_cutoff_cmd = 0;  // unit: mbar
volatile uint32_t eng_knock_intake_cyl_right_pres_cutoff_cmd = 0; // unit: mbar

/**
 * @brief Turbocharger control variables
 */
volatile uint32_t eng_turbo_left_wastegate_cmd = 0; // unit: 1/10 %
volatile uint32_t eng_turbo_left_wastegate = 0;     // unit: 1/10 %

volatile uint32_t eng_turbo_right_wastegate_cmd = 0; // unit: 1/10 %
volatile uint32_t eng_turbo_right_wastegate = 0;     // unit: 1/10 %

volatile uint32_t eng_turbo_left_popoff_cmd = 0;  // unit: 1/10 %
volatile uint32_t eng_turbo_right_popoff_cmd = 0; // unit: 1/10 %

/**
 * @brief Fueling control variables
 */
volatile type_eng_fuel_state eng_fuel_state[CYLINDER_COUNT] = {type_eng_fuel_state::OFF};
volatile type_eng_injector_state eng_injector_state[CYLINDER_COUNT] = {type_eng_injector_state::CLOSED};
volatile uint32_t eng_fuel_injector_duration_cmd[CYLINDER_COUNT] = {0}; // unit: 1/10 ms

/**
 * @brief Ignition control variables
 */
volatile type_eng_ignition_state eng_ignition_state[CYLINDER_COUNT] = {type_eng_ignition_state::OFF};
volatile type_eng_ignition_coil_state eng_ignition_coil_state[CYLINDER_COUNT] = {type_eng_ignition_coil_state::OFF};
volatile uint32_t eng_ignition_timing_cmd[CYLINDER_COUNT] = {0}; // unit: 1/10 ° before OT

/**
 * @brief Coolant circuit control
 */
volatile uint32_t cool_coolant_dutycycle_cmd = 0;  // unit: %
volatile uint32_t cool_ic_water_dutycycle_cmd = 0; // unit: %

/**
 * @brief VTEC solenoid control
 */
volatile type_eng_vtec_solenoid_state eng_vtec_solenoid_state = type_eng_vtec_solenoid_state::OFF;

/**
 * @brief Power control variables
 */
volatile int32_t eng_torque_cmd = 0; // unit: 1/10 Nm
volatile int32_t eng_torque = 0;     // unit: 1/10 Nm

volatile bool eng_torque_enginebrake_allowed = true;

/**
 * @brief Driver input variables
 */
volatile uint32_t driver_throttle_cmd = 0;   // unit: 1/10 %
volatile uint32_t driver_throttle_delta = 0; // unit: 1/10 %   note: derivate over the last 200ms

volatile type_driver_brake_pressed driver_brake_pressed = type_driver_brake_pressed::DEPRESSED;
volatile type_driver_parking_brake_engaged driver_parking_brake_engaged = type_driver_parking_brake_engaged::DISENGAGED;

volatile bool driver_downshift_pedal_pressed = 0;
volatile uint32_t driver_downshift_pedal_press_duration = 0; // unit: ms

volatile bool driver_upshift_pedal_pressed = 0;
volatile uint32_t driver_upshift_pedal_press_duration = 0; // unit: ms