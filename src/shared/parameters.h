/*
 * Project Sakura - Akeno
 * Copyright (C) 2020 Glenn Toews
 * This software is licensed under the LGPLv3 license
 */

/**
 * @file parameters.h
 * @author Glenn Toews
 * @date 12 Nov 2020
 * @brief This file defines the parameters and lookup tables used for
 *        the power train control
 */

#include "stdint.h"

/**
 * @brief Lookup tables for engine ignition control
 */

volatile struct param_eng_ignition_spark_dwell
{
    // X index: voltage (mV)
    // values: Dwell time (µs)
    static const uint32_t x_size = 10;
    const uint32_t x_index[x_size] = {0};
    const uint32_t values[x_size] = {0};
};

volatile struct param_eng_ignition_timing_102oct_no_vtec
{
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: ignition timing (1/10 ° before OT)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const int32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_ignition_timing_102oct_vtec
{
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: ignition timing (1/10 ° before OT)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const int32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_ignition_timing_95oct_no_vtec
{
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: ignition timing (1/10 ° before OT)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const int32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_ignition_timing_95oct_vtec
{
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: ignition timing (1/10 ° before OT)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const int32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_min_ignition_timing
{
    // Defines the minimum ignition timing during strong load changes (i.e. shifting)
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: ignition timing (1/10 ° before OT)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const int32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_min_ignition_allowed_mix
{
    // Defines the allowed mix between norm timing and minmal timing during strong load changes (i.e. shifting)
    // X index: engine performance mode
    // Y index: engine emergency mode
    // values: max. percentage of min. ignition timing (%)
    static const uint32_t x_size = 7;
    static const uint32_t y_size = 4;
    const uint32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_min_ignition_power_loss
{
    // Defines the amount of torque lost with minimal timing compare to 102oct norm
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: engine output torque ratio (compared to 102oct norm values) (%)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const int32_t values[x_size][y_size] = {0};
};

/**
 * @brief Lookup tables for turbocharger control
 */
volatile struct param_eng_turbo_max_boost
{
    // X index: engine speed (rpm)
    // Y index: engine emergency state
    // values: max allowed boost (mbar)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 4;
    const uint32_t values[x_size][y_size] = {0};
};

/**
 * @brief Lookup tables for engine fuel control
 */

volatile struct param_eng_fuel_injector_dead_times
{
    // X index: voltage (mV)
    // values: Dead times (µs)
    static const uint32_t x_size = 10;
    const uint32_t x_index[x_size] = {0};
    const uint32_t values[x_size] = {0};
};

volatile uint32_t param_eng_fuel_injector_size = 0; // unit: cc

volatile uint32_t param_eng_fuel_cylinder_displacement = 0; // unit: 1/10 cm^3

volatile struct param_eng_fuel_injector_timing
{
    // X index: engine speed (rpm)
    // Y index: engine coolant temperature (1/10 °C)
    // values: Injector timing (° before OT (3/4))
    static const uint32_t x_size = 10;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 5;
    const uint32_t y_index[y_size] = {0};
    const uint32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_fuel_af_ratio
{
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // Z index: engine coolant temperature (1/10 °C)
    // values: Target AF ratio (100 * lambda)
    static const uint32_t x_size = 20;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    static const uint32_t z_size = 5;
    const uint32_t z_index[z_size] = {0};
    const uint32_t values[x_size][y_size][z_size] = {0};
};

volatile struct param_eng_fuel_ve_no_vtec
{
    // X index: engine speed (rpm)
    // Y index: throttle body position (1/10 %)
    // values: pressure ratio (1/10 %)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 30;
    const uint32_t y_index[y_size] = {0};
    const uint32_t values[x_size][y_size] = {0};
};

volatile struct param_eng_fuel_ve_vtec
{
    // X index: engine speed (rpm)
    // Y index: throttle body position (1/10 %)
    // values: pressure ratio (1/10 %)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 30;
    const uint32_t y_index[y_size] = {0};
    const uint32_t values[x_size][y_size] = {0};
};

/**
 * @brief Lookup tables for sensor inputs
 */
volatile struct param_eng_lambda
{
    // X index: lambda voltage (mV)
    // values: af ratio (1/100 lambda)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    const uint32_t values[x_size] = {0};
};

volatile uint32_t param_eng_temp_exhaust_min_resistance = 0; // unit: mOhm  note: resistance at 0°C
volatile uint32_t param_eng_temp_exhaust_delta = 0;          // unit: mOhm/°C

/**
 * @brief Engine pressure and torque correlation (at 102oct and norm emergency state)
 */
volatile struct param_eng_torque_map
{
    // X index: engine speed (rpm)
    // Y index: intake cylinder pressures (mbar)
    // values: output torque (Nm)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 20;
    const uint32_t y_index[y_size] = {0};
    const uint32_t values[x_size][y_size] = {0};
};

/**
 * @brief Driver mapping
 */
volatile struct param_driver_torque_demand
{
    // X index: engine speed (rpm)
    // Y index: throttle pedal position (1/10 %)
    // Z index: engine performance state
    // values: demanded torque (Nm)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 30;
    const uint32_t y_index[y_size] = {0};
    static const uint32_t z_size = 7;
    const uint32_t values[x_size][y_size][z_size] = {0};
};

volatile struct param_driver_torque_demand_delta_factor
{
    // X index: engine speed (rpm)
    // Y index: throttle pedal delta (1/10 % / 200ms)
    // Z index: engine performance state
    // values: torque manipulation (1/10 %)
    static const uint32_t x_size = 30;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 10;
    const uint32_t y_index[y_size] = {0};
    static const uint32_t z_size = 7;
    const uint32_t values[x_size][y_size][z_size] = {0};
};

/**
 * @brief Performance state mappings
 */
volatile struct param_eng_max_ignition_retard_compensation
{
    // Defining the maximum amount of ignition retard for throttle tip-out compensation
    // X index: engine performance state
    // values: max. ignition retard
    static const uint32_t x_size = 7;
    const uint32_t x_index[x_size] = {0};
    const uint32_t values[x_size] = {0};
};

volatile struct param_eng_max_downshift_torque_request
{
    // Defining the maximum amount of short term torque demand during downshift (rpm syncing)
    // X index: engine performance state
    // Y index: engine speed (rpm)
    // values: max. torque demand (Nm)
    static const uint32_t x_size = 7;
    const uint32_t x_index[x_size] = {0};
    static const uint32_t y_size = 10;
    const uint32_t y_index[y_size] = {0};
    const uint32_t values[x_size][y_size] = {0};
};
