/* ----------------------------------------------------------------------------
 * ergoDOX layout : Erincalling
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// media key aliases
#define _prev       MEDIAKEY_PREV_TRACK
#define _playpause  MEDIAKEY_PLAY_PAUSE
#define _next       MEDIAKEY_NEXT_TRACK

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
      _esc,         _1,         _2,      _3,      _4, _5,
      _tab,     _quote,     _comma, _period,      _P, _Y,
     _guiL,         _A,         _O,      _E,      _U, _I,
   _shiftL, _semicolon,         _Q,      _J,      _K, _X,
     _home,     _grave,     _equal, _arrowL, _arrowR,
                                                 _ctrlL, _altL,
                                                             1,
                                            _bs,   _del, _guiL,

// right hand
           _6,      _7,      _8,        _9,        _0, _backslash,
           _F,      _G,      _C,        _R,        _L,     _slash,
           _D,      _H,      _T,        _N,        _S,      _dash,
           _B,      _M,      _W,        _V,        _Z,    _shiftR,
               _arrowU, _arrowD, _bracketL, _bracketR,       _end,
 _altR, _ctrlR,
     1,
 _guiR, _enter, _space ),


	KB_MATRIX_LAYER(  // layout: layer 1: media keys and numpad
// unused
0,
// left hand
      0,         _F1,    _F2,         _F3,       _F4,  _F5,
      0,           0,  _mute,    _volumeD,  _volumeU,    0,
      0,           0,  _prev,  _playpause,     _next,    0,
      0,           0,      0,           0,         0,    0,
 _pageU,           0,      0,           0,         0,
                               0,  0,
                                   0,
                           0,  0,  0,
// right hand
           _F6,    _F7,   _F8,       _F9,      _F10,        0,
             0,     _7,    _8,        _9,   _add_kp,        0,
             0,     _4,    _5,        _6,    _equal,        0,
             0,     _1,    _2,        _3,         0,        0,
                    _0,    _0,   _period,         0,   _pageD,
  0,  0,
  0,
  0,  0,  0 ),

	KB_MATRIX_LAYER(  // layout: layer 2: QWERTY layer
// unused
0,
// left hand
  0,   0,   0,   0,   0,   0,
  0,  _Q,  _W,  _E,  _R,  _T,
  0,  _A,  _S,  _D,  _F,  _G,
  0,  _Z,  _X,  _C,  _V,  _B,
  0,  0,  0,  0,  0,
		          0,  0,
		              0,
		      0,  0,  0,
           0,   0,   0,       0,                 0, _bracketR,
          _Y,  _U,  _I,      _O,                _P, _bracketL,
          _H,  _J,  _K,      _L,        _semicolon,    _quote,
          _N,  _M,  _comma,  _period,       _slash,         0,
	              0,   0,      _dash,      _equal_kp,         2,
  0,  0,
          0,
  0,  0,  0 ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  mprrel  &kbfun_mediakey_press_release
#define  ltog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush    &kbfun_layer_push
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop     &kbfun_layer_pop
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0
// unused
NULL,
// left hand
 kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel,  kprrel,
                                                           lpush,
                                         kprrel, kprrel,  kprrel,
// right hand
           kprrel, kprrel, kprrel, kprrel, kprrel,  kprrel,
           kprrel, kprrel, kprrel, kprrel, kprrel,  kprrel,
           kprrel, kprrel, kprrel, kprrel, kprrel,  kprrel,
           kprrel, kprrel, kprrel, kprrel, kprrel,  kprrel,
                   kprrel, kprrel, kprrel, kprrel,  kprrel,
 kprrel, kprrel,
  lpush,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1
// unused
NULL,
// left hand
 ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel,
 ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  ktrans,
 ktrans,  kprrel,  mprrel,  mprrel,  mprrel,  ktrans,
 ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans,
 kprrel,  ktrans,  ktrans,  ktrans,  ktrans,
                                                 ktrans,  ktrans,
                                                          ktrans,
                                         ktrans,  ktrans, ktrans,
// right hand
           kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  dbtldr,
           ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  ktrans,
           ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  ktrans,
           ktrans,  kprrel,  kprrel,  kprrel,  ktrans,  ktrans,
                    kprrel,  kprrel,  kprrel,  ktrans,  kprrel,
 ktrans,  ktrans,
 ktrans,
 ktrans,  ktrans,  ktrans ),


	KB_MATRIX_LAYER(  // press: layer 2
// unused
NULL,
// left hand
//
   ktrans,   ktrans,   ktrans,   ktrans,   ktrans,   ktrans,
   ktrans,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
   ktrans,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
   ktrans,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
   ktrans,   ktrans,   ktrans,   ktrans,   ktrans,
                                                   ktrans,   ktrans,
                                                             ktrans,
                                           ktrans, ktrans,   ktrans,
// right hand
           ktrans,   ktrans,   ktrans,   ktrans,   ktrans,   kprrel,
           kprrel,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
           kprrel,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
           kprrel,   kprrel,   kprrel,   kprrel,   kprrel,   ktrans,
                     ktrans,   ktrans,   kprrel,   kprrel,     lpop,
   ktrans,   ktrans,
   ktrans,
   ktrans,   ktrans,   ktrans ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                                           lpop,
                                         kprrel, kprrel, kprrel,
// right hand
           kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
           kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
           kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
           kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                   kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
   lpop,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 1
// unused
NULL,
// left hand
 ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel,
 ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  ktrans,
 ktrans,  kprrel,  mprrel,  mprrel,  mprrel,  ktrans,
 ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans,
 kprrel,  ktrans,  ktrans,  ktrans,  ktrans,
                                                 ktrans,  ktrans,
                                                          ktrans,
                                         ktrans,  ktrans, ktrans,
// right hand
           kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  dbtldr,
           ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  ktrans,
           ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  ktrans,
           ktrans,  kprrel,  kprrel,  kprrel,  ktrans,  ktrans,
                    kprrel,  kprrel,  kprrel,  ktrans,  kprrel,
 ktrans,  ktrans,
 ktrans,
 ktrans,  ktrans,  ktrans ),


	KB_MATRIX_LAYER(  // release: layer 2
// unused
NULL,
// left hand
//
   ktrans,   ktrans,   ktrans,   ktrans,   ktrans,   ktrans,
   ktrans,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
   ktrans,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
   ktrans,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
   ktrans,   ktrans,   ktrans,   ktrans,   ktrans,
                                                   ktrans,   ktrans,
                                                             ktrans,
                                           ktrans, ktrans,   ktrans,
// right hand
           ktrans,   ktrans,   ktrans,   ktrans,   ktrans,   kprrel,
           kprrel,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
           kprrel,   kprrel,   kprrel,   kprrel,   kprrel,   kprrel,
           kprrel,   kprrel,   kprrel,   kprrel,   kprrel,   ktrans,
                     ktrans,   ktrans,   kprrel,   kprrel,   kprrel,
   ktrans,   ktrans,
   ktrans,
   ktrans,   ktrans,   ktrans ),

	KB_MATRIX_LAYER(  // Not a real layer; just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,
   ltog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL )

};
