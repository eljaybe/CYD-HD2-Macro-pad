/*
 * Helldivers 2 BLE Macro Pad
 * Copyright (C) 2026 Leo Beauchamp
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "stratagem.h"

const int TOTAL_STRATAGEMS = 110;

const char* catNames[] = {
    "ORBITAL STRIKES", "EAGLE STRIKES", "SUPPORT WEAPONS", "BACKPACKS",
    "VEHICLES", "SENTRIES", "EMPLACEMENTS", "MISSION ITEMS"
};


Stratagem library[TOTAL_STRATAGEMS] = {
    {"ORB PRECISION", 0, 0, 90, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 3, icon_orbital_precision_strike_stratagem_icon_background},
    {"ORB GATLING",   0, 0, 70, {KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 5, icon_orbital_gatling_barrage_stratagem_icon_background},
    {"ORB GAS STRIKE",0, 0, 75, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 4, icon_orbital_gas_strike_stratagem_icon_background},
    {"ORB 120MM HE",  0, 0, 180, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 6, icon_orbital_120mm_he_barrage_stratagem_icon_background},
    {"ORB AIRBURST",  0, 0, 100, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW}, 3, icon_orbital_airburst_strike_stratagem_icon_background},
    {"ORB SMOKE",     0, 0, 75, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 4, icon_orbital_smoke_strike_stratagem_icon_background},
    {"ORB EMS STRIKE",0, 0, 75, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW}, 4, icon_orbital_ems_strike_stratagem_icon_background},
    {"ORB 380MM HE",  0, 0, 240, {KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 7, icon_orbital_380mm_he_barrage_stratagem_icon_background},
    {"ORB WALKING",   0, 0, 240, {KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 6, icon_orbital_walking_barrage_stratagem_icon_background},
    {"ORB LASER",     0, 0, 300, {KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 5, icon_orbital_laser_stratagem_icon_background},
    {"ORB NAPALM",    0, 0, 240, {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 6, icon_orbital_napalm_barrage_stratagem_icon_background},
    {"ORB RAILCANNON",0, 0, 180, {KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 5, icon_orbital_railcannon_strike_stratagem_icon_background},
    {"EAGLE STRAFING",0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW}, 3, icon_eagle_strafing_run_stratagem_icon_background},
    {"EAGLE AIRSTRIK",0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 4, icon_eagle_airstrike_stratagem_icon_background},
    {"EAGLE GASSTRIK",0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 4, icon_eagle_gas_strike_stratagem_icon_background},
    {"EAGLE CLUSTER", 0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 5, icon_eagle_cluster_bomb_stratagem_icon_background},
    {"EAGLE SMOKE",   0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}, 4, icon_eagle_smoke_strike_stratagem_icon_background},
    {"EAGLE NAPALM",  0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 4, icon_eagle_napalm_airstrike_stratagem_icon_background},
    {"EAGLE ROCKETS", 0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW}, 4, icon_eagle_110mm_rocket_pods_stratagem_icon_background},
    {"EAGLE 500KG",   0, 1, 15, {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 5, icon_eagle_500kg_bomb_stratagem_icon_background},
    {"MG MACHINE GUN",1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 5, icon_machine_gun_stratagem_icon_background},
    {"EAT-17 AT",     1, 2, 70,  {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 5, icon_expendable_anti_tank_stratagem_icon_background},
    {"STALWART",      1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW}, 6, icon_stalwart_stratagem_icon_background},
    {"LASER CANNON",  1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW}, 5, icon_laser_cannon_stratagem_icon_background},
    {"ANTI-MAT RIFLE",1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}, 5, icon_anti_materiel_rifle_stratagem_icon_background},
    {"GRENADE LAUNCH",1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW}, 5, icon_grenade_launcher_stratagem_icon_background},
    {"RECOILLESS RFL",1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW}, 5, icon_recoilless_rifle_stratagem_icon_background},
    {"FLAMETHROWER",  1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 5, icon_flamethrower_stratagem_icon_background},
    {"HEAVY MG",      1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 5, icon_heavy_machine_gun_stratagem_icon_background},
    {"AUTOCANNON",    1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 6, icon_autocannon_stratagem_icon_background},
    {"ARC THROWER",   1, 2, 480, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW}, 6, icon_arc_thrower_stratagem_icon_background},
    {"QUASAR CANNON", 1, 2, 480, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 5, icon_quasar_cannon_stratagem_icon_background},
    {"AIRBURST RKT",  1, 2, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 5, icon_airburst_rocket_launcher_stratagem_icon_background},
    {"COMMANDO",      1, 2, 120, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 5, icon_commando_stratagem_icon_background},
    {"SPEAR LAUNCHER",1, 2, 480, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 5, icon_spear_stratagem_icon_background},
    {"RAILGUN",       1, 2, 480, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 6, icon_railgun_stratagem_icon_background},
    {"W.A.S.P. LCH",  1, 2, 480, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 5, icon_w_a_s_p__launcher_stratagem_icon_background},
    {"BREACHING HAM", 1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW}, 5, icon_breaching_hammer_stratagem_icon_background},
    {"EPOCH PLAS",    1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 5, icon_epoch_stratagem_icon_background},
    {"BULLET STORM",  1, 2, 70,  {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW}, 6, icon_bullet_storm_stratagem_icon_background},
    {"SPEARGUN",      1, 2, 480, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 6, icon_speargun_stratagem_icon_background},
    {"DEFOLIATOR",    1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 5, icon_defoliation_tool_stratagem_icon_background},
    {"STERILIZER",    1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW}, 5, icon_sterilizer_stratagem_icon_background},
    {"EXP NAPALM",    1, 2, 140, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW}, 5, icon_expendable_napalm_stratagem_icon_background},
    {"LEVELLER",      1, 2, 140, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}, 5, icon_leveller_stratagem_icon_background},
    {"DE-ESCALATOR",  1, 2, 480, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 5, icon_de_escalator_stratagem_icon_background},
    {"BELT GRENADE",  1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 6, icon_belt_fed_grenade_launcher_stratagem_icon_background},
    {"C4 PACK",       1, 2, 480, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 6, icon_c4_pack_stratagem_icon_background},
    {"SOLO SILO",     1, 2, 180, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 5, icon_solo_silo_stratagem_icon_background},
    {"CREMATOR",      1, 2, 480, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 6, icon_cremator_stratagem_icon_background},
    {"MAXIGUN",       1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 6, icon_maxigun_stratagem_icon_background},
    {"MELTAGUN",      1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW}, 6, icon_meltagun_stratagem_icon_background},
    {"ONE TRUE FLAG2",1, 2, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 5, icon_one_true_flag_stratagem_icon_background},
    {"SUPPLY PACK",   1, 3, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}, 6, icon_supply_pack_stratagem_icon_background},
    {"JUMP PACK",     1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 5, icon_jump_pack_stratagem_icon_background},
    {"BALLISTIC SHLD",1, 3, 240, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW}, 6, icon_ballistic_shield_backpack_stratagem_icon_background},
    {"GD AR23",       1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 6, icon_guard_dog_stratagem_icon_background},
    {"GD LAS ROVER",  1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW}, 6, icon_rover_stratagem_icon_background},
    {"SHIELD PACK",   1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 6, icon_shield_generator_pack_stratagem_icon_background},
    {"DIR SHIELD",    1, 3, 300, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 6, icon_directional_shield_stratagem_icon_background},
    {"GD HOT DOG",    1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW}, 6, icon_hot_dog_stratagem_icon_background},
    {"PORT HELLBOMB", 1, 3, 300, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 5, icon_portable_hellbomb_stratagem_icon_background},
    {"GD K-9 ARC",    1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW}, 6, icon_k_9_stratagem_icon_background},
    {"HOVER PACK",    1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 6, icon_hover_pack_stratagem_icon_background},
    {"GD DOG BREATH", 1, 3, 480, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 6, icon_dog_breath_stratagem_icon_background},
    {"WARP PACK",     1, 3, 480, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 6, icon_warp_pack_stratagem_icon_background},
    {"SUPPLY FRV",    1, 4, 480, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 7, icon_supply_frv_stratagem_icon_background},
    {"INCINERATR FRV",1, 4, 480, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 7, icon_incinerator_frv_stratagem_icon_background},
    {"EMANCIPTR EXO", 1, 4, 420, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 7, icon_emancipator_exosuit_stratagem_icon_background},
    {"PATRIOT EXO",   1, 4, 420, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 7, icon_patriot_exosuit_stratagem_icon_background},
    {"FAST RECON",    1, 4, 480, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 7, icon_fast_recon_vehicle_stratagem_icon_background},
    {"BASTION TANK",  1, 4, 780, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 9, icon_bastion_mk_xvi_stratagem_icon_background},
    {"BREAKTHR EXO",  1, 4, 420, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 7, icon_breakthrough_exosuit_stratagem_icon_background},
    {"LUMBERER EXO",  1, 4, 420, {KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW}, 7, icon_lumberer_exosuit_stratagem_icon_background},
    {"SNT MACHINEGUN",2, 5, 90,  {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 5, icon_machine_gun_sentry_stratagem_icon_background},
    {"SNT GATLING",   2, 5, 150, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW}, 4, icon_gatling_sentry_stratagem_icon_background},
    {"SNT AUTOCANNON",2, 5, 150, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW}, 6, icon_autocannon_sentry_stratagem_icon_background},
    {"SNT MORTAR",    2, 5, 180, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 5, icon_mortar_sentry_stratagem_icon_background},
    {"SNT ROCKET",    2, 5, 150, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW}, 5, icon_rocket_sentry_stratagem_icon_background},
    {"TESLA TOWER",   2, 5, 120, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 6, icon_tesla_tower_stratagem_icon_background},
    {"SNT EMS MORTAR",2, 5, 180, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}, 5, icon_ems_mortar_sentry_stratagem_icon_background},
    {"SNT LASER",     2, 5, 150, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 6, icon_laser_sentry_stratagem_icon_background},
    {"SNT FLAME",     2, 5, 100, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 6, icon_flame_sentry_stratagem_icon_background},
    {"SNT GAS MORTAR",2, 5, 180, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW}, 5, icon_gas_mortar_sentry_stratagem_icon_background},
    {"MINEFIELD AP",  2, 6, 120, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 4, icon_anti_personnel_minefield_stratagem_icon_background},
    {"MINEFIELD INC", 2, 6, 120, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW}, 4, icon_incendiary_mines_stratagem_icon_background},
    {"MINEFIELD AT",  2, 6, 120, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 4, icon_anti_tank_mines_stratagem_icon_background},
    {"SHIELD RELAY",  2, 6, 90,  {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 6, icon_shield_generator_relay_stratagem_icon_background},
    {"HMG EMPLACEMNT",2, 6, 180, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW}, 6, icon_hmg_emplacement_stratagem_icon_background},
    {"GREN BATTLEMNT",2, 6, 120, {KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 5, icon_grenadier_battlement_stratagem_icon_background},
    {"MINEFIELD GAS", 2, 6, 120, {KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 4, icon_gas_mines_stratagem_icon_background},
    {"AT EMPLACEMENT",2, 6, 180, {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_RIGHT_ARROW}, 6, icon_anti_tank_emplacement_stratagem_icon_background},
    {"SUPER DESTROYR",3, 7, 0,   {KEY_UP_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW}, 8, icon_call_in_super_destroyer_stratagem_icon_background},
    {"EAGLE REARM",   3, 7, 0,   {KEY_UP_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 5, icon_eagle_rearm_stratagem_icon_background},
    {"RESUPPLY",      3, 7, 180, {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW}, 4, icon_resupply_stratagem_icon_background},
    {"SOS BEACON",    3, 7, 0,   {KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW}, 4, icon_sos_beacon_stratagem_icon_background},
    {"REINFORCE",     3, 7, 0,   {KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_UP_ARROW}, 5, icon_reinforce_stratagem_icon_background},
    {"CARGO CONTAIN", 3, 7, 0,   {KEY_UP_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW}, 6, icon_cargo_container_stratagem_icon_background},
    {"DARK FLUID",    3, 7, 30,  {KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 6, icon_dark_fluid_vessel_stratagem_icon_background},
    {"HELLBOMB NUX",  3, 7, 30,  {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 8, icon_hellbomb_stratagem_icon_background},
    {"SEAF ARTILLERY",3, 7, 0,   {KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}, 4, icon_seaf_artillery_stratagem_icon_background},
    {"SEISMIC PROBE", 3, 7, 0,   {KEY_UP_ARROW, KEY_UP_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 6, icon_seismic_probe_stratagem_icon_background},
    {"SUPR EARTH FLG",3, 7, 0,   {KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW}, 4, icon_super_earth_flag_stratagem_icon_background},
    {"TECTONIC DRILL",3, 7, 0,   {KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW}, 6, icon_drill_stratagem_icon_background},
    {"UPLOAD DATA",   3, 7, 0,   {KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 5, icon_upload_data_stratagem_icon_background},
    {"HIVE DRILL",    3, 7, 0,   {KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 6, icon_drill_stratagem_icon_background},
    {"REINFORCE PODS",3, 7, 0,   {KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 5, icon_upload_data_stratagem_icon_background},
    {"SSSD DELIVERY", 3, 7, 0,   {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_UP_ARROW, KEY_UP_ARROW}, 7, icon_upload_data_stratagem_icon_background},
    {"PROSPECT DRILL",3, 7, 0,   {KEY_DOWN_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_DOWN_ARROW}, 6, icon_drill_stratagem_icon_background},
    {"ORB FLARE",     3, 7, 0,   {KEY_RIGHT_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_LEFT_ARROW}, 4, icon_orbital_illumination_flare_stratagem_icon_background}
    };
