#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "oled.h"
#endif

#include "edvorakjp.h"

/*
 * enum custom_keycodes {
 *   KC_LOCK = NEW_SAFE_RANGE,
 * };
 */

#define KC_ KC_TRNS

#define KC_TMB1 KC_ESC
#define KC_TMB2 KC_LA(TAB)
#define KC_TMB3 KC_LS(SPC)
#define KC_TMB4 TD(TD_LOWER) // act as LOWER when hold, as KC_LANG2(=English) when tapped
#define KC_TMB5 TD(TD_RAISE) // act as RAISE when hold, as KC_LANG1(=Japanese) when tapped
#define KC_TMB6 KC_RC(BSPC)
#define KC_TMB7 KC_RG(ENT)
#define KC_TMB8 KC_RC(DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_EDVORAK] = LAYOUT_kc(
  //|----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----|
     GRV ,QUOT,COMM , DOT ,  Y  , Q  ,     F  ,  G  ,  R  ,  W  , P  ,BSLS,
  //|----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----|
     EQL , A  ,LA(O),LG(E),LC(I), U  ,     D  ,RS(T),RG(N),RA(S), M  ,MINS,
  //|----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----|
     ESC ,SCLN,  X  ,  C  ,  V  , Z  ,     H  ,  J  ,  K  ,  L  , B  ,SLSH,
  //`----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----'
               TMB1 ,TMB2 ,TMB3 ,TMB4,    TMB5,TMB6 ,TMB7 ,TMB8
  //          `-----+-----+-----+----'   `----+-----+-----+-----'
  ),

  [_LOWER] = LAYOUT_kc(
  //|----+----+------+------+------+----|   |----+------+------+-------+----+----|
         ,    , LCBR , LBRC , LPRN ,    ,        , RPRN , RBRC , RCBR  ,    ,    ,
  //|----+----+------+------+------+----|   |----+------+------+-------+----+----|
      F1 , F2 ,LA(F3),LG(F4),LC(F5), F6 ,     F7 ,RS(F8),RG(F9),RA(F10),F11 ,F12 ,
  //|----+----+------+------+------+----|   |----+------+------+-------+----+----|
     PSCR,    , HOME , PGDN , PGUP ,END ,    LEFT, DOWN ,  UP  , RGHT  ,    ,    ,
  //`----+----+------+------+------+----|   |----+------+------+-------+----+----'
                     ,      ,      ,    ,        ,      ,      ,
  //          `------+------+------+----'   `----+------+------+-------'
  ),

  [_RAISE] = LAYOUT_kc(
  //|----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----|
         ,    ,EXLM , AT  ,HASH ,DLR ,    PERC,CIRC ,AMPR ,ASTR ,    ,    ,
  //|----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----|
         , 1  ,LA(2),LG(3),LC(4), 5  ,     6  ,RS(7),RG(8),RA(9), 0  ,    ,
  //|----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----|
     PSCR,    ,HOME ,PGDN ,PGUP ,END ,    LEFT,DOWN , UP  ,RGHT ,    ,    ,
  //`----+----+-----+-----+-----+----|   |----+-----+-----+-----+----+----'
                    ,     ,     ,    ,        ,     ,     ,
  //          `-----+-----+-----+----'   `----+-----+-----+-----'
  )
};

#ifdef SSD1306OLED
void matrix_init_keymap(void) {
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef MASTER_RIGHT
  iota_gfx_init(has_usb()); // turns on the display
#else
  iota_gfx_init(!has_usb());
#endif // MASTER_RIGHT
}

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}
#endif
