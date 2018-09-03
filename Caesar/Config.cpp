#include <fstream>
#include <ShlObj.h>
//#include <windef.h>

#include "json/json.h"

#include "Config.h"

Config::Config(const std::string& name)
{
    char buff[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, buff))) {
        path = buff + '\\' + name;
    }
}

void Config::init()
{
    hide_from_obs = false;

    aim = false;
    aim_teammates = false;
    aim_delay_shot = false;
    aim_target_selection = 3;
    aim_hitbox = 1;
    aim_multi_point = 0;
    aim_penetration = false;
    aim_silent = false;
    aim_perfect_silent = false;
    aim_autoscope = false;

    fakelag = false;
    fakelag_while_shooting = false;
    fakelag_type = 3;
    fakelag_move = 3;
    fakelag_variance = 0;
    fakelag_limit = 0;

    brightness = 0;
    brightness_r = 0;
    brightness_g = 0;
    brightness_b = 0;

    quick_stop = false;
    quick_stop_duck = false;

    autopistol = false;
    autoreload = false;
    fastzoom = false;

    nosmoke = false;
    remove_scope = false;
    crosshair = false;

    crosshair_r = 255;
    crosshair_g = 255;
    crosshair_b = 255;

    noflash = 0;
    thirdperson = 0;
    disable_render_teammates = false;
    bullets_trace = false;

    esp = false;
    esp_behind = false;
    esp_teammates = false;

    esp_box = false;
    esp_box_ct_vis_r = 0;
    esp_box_ct_vis_g = 100;
    esp_box_ct_vis_b = 255;
    esp_box_t_vis_r = 255;
    esp_box_t_vis_g = 100;
    esp_box_t_vis_b = 0;
    esp_box_ct_invis_r = 0;
    esp_box_ct_invis_g = 255;
    esp_box_ct_invis_b = 255;
    esp_box_t_invis_r = 255;
    esp_box_t_invis_g = 255;
    esp_box_t_invis_b = 0;
    esp_box_friends_r = 0;
    esp_box_friends_g = 255;
    esp_box_friends_b = 0;

    esp_box_outline = false;
    esp_name = false;

    esp_fake = false;
    bypass_trace_blockers = true;
    bypass_valid_blockers = false;
    esp_sound_minimum_volume = 0;

    esp_weapon = 1;
    esp_weapon_r = 255;
    esp_weapon_g = 0;
    esp_weapon_b = 255;

    esp_world_weapon = 1;
    esp_world_weapon_r = 255;
    esp_world_weapon_g = 255;
    esp_world_weapon_b = 255;

    esp_shots_fired = false;

    esp_flags = false;
    esp_distance = false;
    esp_hitboxes = false;
    esp_sound = false;
    esp_health = false;

    esp_alpha = 200;

    esp_line_of_sight = false;

    esp_line_of_sight_r = 255;
    esp_line_of_sight_g = 255;
    esp_line_of_sight_b = 255;

    esp_screen = false;

    esp_bomb = false;
    esp_bomb_r = 255;
    esp_bomb_g = 0;
    esp_bomb_b = 0;

    grenade_trajectory = false;

    glow_players = false;

    glow_players_ct_r = 0;
    glow_players_ct_g = 0;
    glow_players_ct_b = 255;

    glow_players_t_r = 255;
    glow_players_t_g = 0;
    glow_players_t_b = 0;

    hud_clear = false;

    penetration_info = false;

    recoil_overlay_r = 255;
    recoil_overlay_g = 255;
    recoil_overlay_b = 0;

    spread_overlay_r = 255;
    spread_overlay_g = 0;
    spread_overlay_b = 0;

    chams = false;
    chams_behind_wall = false;
    chams_type = 3;

    chams_t_vis_r = 255;
    chams_t_vis_g = 100;
    chams_t_vis_b = 0;

    chams_t_invis_r = 255;
    chams_t_invis_g = 255;
    chams_t_invis_b = 0;

    chams_ct_vis_r = 0;
    chams_ct_vis_g = 100;
    chams_ct_vis_b = 255;

    chams_ct_invis_r = 0;
    chams_ct_invis_g = 255;
    chams_ct_invis_b = 255;

    spread_overlay = false;
    spread_overlay_old = false;
    recoil_overlay = false;

    draw_aim_fov = false;
    draw_aim_fov_r = 255;
    draw_aim_fov_g = 255;
    draw_aim_fov_b = 0;

    norecoil = false;
    norecoil_visual = false;

    nospread = false;
    nospread_method = 1;

    aa_yaw_while_running = 0;
    aa_yaw = 0;
    aa_yaw_static = 0;
    aa_pitch = 0;
    aa_edge = 0;

    legit_teammates = false;
    trigger_only_zoomed = false;
    block_attack_after_kill = 0;
    trigger_key = -1;

    menu_legit_global_section = 1;
    menu_legit_sub_section = 1;
    menu_key = 45;
    menu_color_r = 215;
    menu_color_g = 111;
    menu_color_b = 234;

    bunnyhop = false;
    knifebot = false;

    name_stealer = false;

    debug = false;
}

void Config::load()
{
    std::ifstream in{ path };

    if (!in.is_open())
        return;

    Json::Value config;
    in >> config;



}

void Config::save()
{
    std::ofstream out{ path };

    if (!out.is_open())
        return;

    Json::Value config;

    config["hide_from_obs"] = hide_from_obs;
    config["aim"] = aim;
    config["aim_teammates"] = aim_teammates;
    config["aim_delay_shot"] = aim_delay_shot;
    config["aim_target_selection"] = aim_target_selection;
    config["aim_hitbox"] = aim_hitbox;
    config["aim_multi_point"] = aim_multi_point;
    config["aim_penetration"] = aim_penetration;
    config["aim_silent"] = aim_silent;
    config["aim_perfect_silent"] = aim_perfect_silent;
    config["aim_autoscope"] = aim_autoscope;
    config["quick_stop"] = quick_stop;
    config["quick_stop_duck"] = quick_stop_duck;
    config["fakelag"] = fakelag;
    config["fakelag_while_shooting"] = fakelag_while_shooting;
    config["fakelag_type"] = fakelag_type;
    config["fakelag_move"] = fakelag_move;
    config["fakelag_variance"] = fakelag_variance;
    config["fakelag_limit"] = fakelag_limit;
    config["brightness"] = brightness;
    config["brightness_r"] = brightness_r;
    config["brightness_g"] = brightness_g;
    config["brightness_b"] = brightness_b;
    config["autopistol"] = autopistol;
    config["autoreload"] = autoreload;
    config["fastzoom"] = fastzoom;
    config["nosmoke"] = nosmoke;
    config["remove_scope"] = remove_scope;
    config["crosshair"] = crosshair;
    config["crosshair_r"] = crosshair_r;
    config["crosshair_g"] = crosshair_g;
    config["crosshair_b"] = crosshair_b;
    config["thirdperson"] = thirdperson;
    config["disable_render_teammates"] = disable_render_teammates;
    config["bullets_trace"] = bullets_trace;
    config["noflash"] = noflash;
    config["esp"] = esp;
    config["esp_behind"] = esp_behind;
    config["esp_teammates"] = esp_teammates;
    config["esp_box"] = esp_box;
    config["esp_box_ct_vis_r"] = esp_box_ct_vis_r;
    config["esp_box_ct_vis_g"] = esp_box_ct_vis_g;
    config["esp_box_ct_vis_b"] = esp_box_ct_vis_b;
    config["esp_box_t_vis_r"] = esp_box_t_vis_r;
    config["esp_box_t_vis_g"] = esp_box_t_vis_g;
    config["esp_box_t_vis_b"] = esp_box_t_vis_b;
    config["esp_box_ct_invis_r"] = esp_box_ct_invis_r;
    config["esp_box_ct_invis_g"] = esp_box_ct_invis_g;
    config["esp_box_ct_invis_b"] = esp_box_ct_invis_b;
    config["esp_box_t_invis_r"] = esp_box_t_invis_r;
    config["esp_box_t_invis_g"] = esp_box_t_invis_g;
    config["esp_box_t_invis_b"] = esp_box_t_invis_b;
    config["esp_box_friends_r"] = esp_box_friends_r;
    config["esp_box_friends_g"] = esp_box_friends_g;
    config["esp_box_friends_b"] = esp_box_friends_b;
    config["esp_box_outline"] = esp_box_outline;
    config["esp_name"] = esp_name;
    config["esp_fake"] = esp_fake;
    config["bypass_trace_blockers"] = bypass_trace_blockers;
    config["bypass_valid_blockers"] = bypass_valid_blockers;
    config["esp_sound_minimum_volume"] = esp_sound_minimum_volume;
    config["esp_weapon"] = esp_weapon;
    config["esp_weapon_r"] = esp_weapon_r;
    config["esp_weapon_g"] = esp_weapon_g;
    config["esp_weapon_b"] = esp_weapon_b;
    config["esp_world_weapon"] = esp_world_weapon;
    config["esp_world_weapon_r"] = esp_world_weapon_r;
    config["esp_world_weapon_g"] = esp_world_weapon_g;
    config["esp_world_weapon_b"] = esp_world_weapon_b;
    config["esp_flags"] = esp_flags;
    config["esp_distance"] = esp_distance;
    config["esp_hitboxes"] = esp_hitboxes;
    config["esp_sound"] = esp_sound;
    config["esp_health"] = esp_health;
    config["esp_alpha"] = esp_alpha;
    config["esp_line_of_sight"] = esp_line_of_sight;
    config["esp_line_of_sight_r"] = esp_line_of_sight_r;
    config["esp_line_of_sight_g"] = esp_line_of_sight_g;
    config["esp_line_of_sight_b"] = esp_line_of_sight_b;
    config["esp_screen"] = esp_screen;
    config["esp_shots_fired"] = esp_shots_fired;
    config["esp_bomb"] = esp_bomb;
    config["esp_bomb_r"] = esp_bomb_r;
    config["esp_bomb_g"] = esp_bomb_g;
    config["esp_bomb_b"] = esp_bomb_b;
    config["hud_clear"] = hud_clear;
    config["penetration_info"] = penetration_info;
    config["recoil_overlay_r"] = recoil_overlay_r;
    config["recoil_overlay_g"] = recoil_overlay_g;
    config["recoil_overlay_b"] = recoil_overlay_b;
    config["spread_overlay_r"] = spread_overlay_r;
    config["spread_overlay_g"] = spread_overlay_g;
    config["spread_overlay_b"] = spread_overlay_b;
    config["grenade_trajectory"] = grenade_trajectory;
    config["chams"] = chams;
    config["chams_behind_wall"] = chams_behind_wall;
    config["chams_type"] = chams_type;
    config["chams_t_vis_r"] = chams_t_vis_r;
    config["chams_t_vis_g"] = chams_t_vis_g;
    config["chams_t_vis_b"] = chams_t_vis_b;
    config["chams_t_invis_r"] = chams_t_invis_r;
    config["chams_t_invis_g"] = chams_t_invis_g;
    config["chams_t_invis_b"] = chams_t_invis_b;
    config["chams_ct_vis_r"] = chams_ct_vis_r;
    config["chams_ct_vis_g"] = chams_ct_vis_g;
    config["chams_ct_vis_b"] = chams_ct_vis_b;
    config["chams_ct_invis_r"] = chams_ct_invis_r;
    config["chams_ct_invis_g"] = chams_ct_invis_g;
    config["chams_ct_invis_b"] = chams_ct_invis_b;
    config["glow_players"] = glow_players;
    config["glow_players_ct_r"] = glow_players_ct_r;
    config["glow_players_ct_g"] = glow_players_ct_g;
    config["glow_players_ct_b"] = glow_players_ct_b;
    config["glow_players_t_r"] = glow_players_t_r;
    config["glow_players_t_g"] = glow_players_t_g;
    config["glow_players_t_b"] = glow_players_t_b;
    config["spread_overlay"] = spread_overlay;
    config["spread_overlay_old"] = spread_overlay_old;
    config["recoil_overlay"] = recoil_overlay;
    config["draw_aim_fov"] = draw_aim_fov;
    config["draw_aim_fov_r"] = draw_aim_fov_r;
    config["draw_aim_fov_g"] = draw_aim_fov_g;
    config["draw_aim_fov_b"] = draw_aim_fov_b;
    config["norecoil"] = norecoil;
    config["norecoil_visual"] = norecoil_visual;
    config["nospread"] = nospread;
    config["nospread_method"] = nospread_method;
    config["aa_yaw_while_running"] = aa_yaw_while_running;
    config["aa_yaw"] = aa_yaw;
    config["aa_yaw_static"] = aa_yaw_static;
    config["aa_pitch"] = aa_pitch;
    config["aa_edge"] = aa_edge;
    config["legit_teammates"] = legit_teammates;
    config["trigger_only_zoomed"] = trigger_only_zoomed;
    config["block_attack_after_kill"] = block_attack_after_kill;
    config["trigger_key"] = trigger_key;
    config["menu_legit_global_section"] = menu_legit_global_section;
    config["menu_legit_sub_section"] = menu_legit_sub_section;
    config["menu_key"] = menu_key;
    config["menu_color_r"] = menu_color_r;
    config["menu_color_g"] = menu_color_g;
    config["menu_color_b"] = menu_color_b;
    config["bunnyhop"] = bunnyhop;
    config["knifebot"] = knifebot;
    config["name_stealer"] = name_stealer;
    config["debug"] = debug;

    for (int i = 1; i < 31; i++) {
        if (i == 2 || i == 4 || i == 6 || i == 9 || i == 25)
            continue;

        std::string weaponName = "weapon_" + std::to_string(i);

        config[weaponName]["aim"] = legit[i].aim;
        config[weaponName]["aim_head"] = legit[i].aim_head;
        config[weaponName]["aim_chest"] = legit[i].aim_chest;
        config[weaponName]["aim_stomach"] = legit[i].aim_stomach;
        config[weaponName]["aim_quick_stop"] = legit[i].aim_quick_stop;
        config[weaponName]["aim_humanize"] = legit[i].aim_humanize;
        config[weaponName]["aim_spread_compenstation"] = legit[i].aim_spread_compenstation;
        config[weaponName]["aim_accuracy"] = legit[i].aim_accuracy;
        config[weaponName]["aim_psilent"] = legit[i].aim_psilent;
        config[weaponName]["aim_fov"] = legit[i].aim_fov;
        config[weaponName]["aim_speed"] = legit[i].aim_speed;
        config[weaponName]["aim_speed_in_attack"] = legit[i].aim_speed_in_attack;
        config[weaponName]["aim_speed_scale_fov"] = legit[i].aim_speed_scale_fov;
        config[weaponName]["aim_recoil_compensation_pitch"] = legit[i].aim_recoil_compensation_pitch;
        config[weaponName]["aim_recoil_compensation_yaw"] = legit[i].aim_recoil_compensation_yaw;
        config[weaponName]["aim_recoil_compensation_after_shots_fired"] = legit[i].aim_recoil_compensation_after_shots_fired;
        config[weaponName]["aim_reaction_time"] = legit[i].aim_reaction_time;
        config[weaponName]["trigger"] = legit[i].trigger;
        config[weaponName]["trigger_head"] = legit[i].trigger_head;
        config[weaponName]["trigger_chest"] = legit[i].trigger_chest;
        config[weaponName]["trigger_stomach"] = legit[i].trigger_stomach;
        config[weaponName]["trigger_penetration"] = legit[i].trigger_penetration;
        config[weaponName]["trigger_accuracy"] = legit[i].trigger_accuracy;
    }
}

