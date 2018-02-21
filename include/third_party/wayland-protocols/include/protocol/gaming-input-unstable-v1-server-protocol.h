/* Generated by wayland-scanner 1.13.0 */

#ifndef GAMING_INPUT_UNSTABLE_V1_SERVER_PROTOCOL_H
#define GAMING_INPUT_UNSTABLE_V1_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_gaming_input_unstable_v1 The gaming_input_unstable_v1 protocol
 * @section page_ifaces_gaming_input_unstable_v1 Interfaces
 * - @subpage page_iface_zcr_gaming_input_v1 - extends wl_seat with gaming input devices
 * - @subpage page_iface_zcr_gamepad_v1 - gamepad input device
 * @section page_copyright_gaming_input_unstable_v1 Copyright
 * <pre>
 *
 * Copyright 2016 The Chromium Authors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_seat;
struct zcr_gamepad_v1;
struct zcr_gaming_input_v1;

/**
 * @page page_iface_zcr_gaming_input_v1 zcr_gaming_input_v1
 * @section page_iface_zcr_gaming_input_v1_desc Description
 *
 * A global interface to provide gaming input devices for a given seat.
 *
 * Currently only gamepad devices are supported.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding uinterface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and uinterface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 * @section page_iface_zcr_gaming_input_v1_api API
 * See @ref iface_zcr_gaming_input_v1.
 */
/**
 * @defgroup iface_zcr_gaming_input_v1 The zcr_gaming_input_v1 interface
 *
 * A global interface to provide gaming input devices for a given seat.
 *
 * Currently only gamepad devices are supported.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding uinterface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and uinterface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 */
extern const struct wl_interface zcr_gaming_input_v1_interface;
/**
 * @page page_iface_zcr_gamepad_v1 zcr_gamepad_v1
 * @section page_iface_zcr_gamepad_v1_desc Description
 *
 * The zcr_gamepad_v1 interface represents one or more gamepad input devices,
 * which are reported as a normalized 'Standard Gamepad' as it is specified
 * by the W3C Gamepad API at: https://w3c.github.io/gamepad/#remapping
 * @section page_iface_zcr_gamepad_v1_api API
 * See @ref iface_zcr_gamepad_v1.
 */
/**
 * @defgroup iface_zcr_gamepad_v1 The zcr_gamepad_v1 interface
 *
 * The zcr_gamepad_v1 interface represents one or more gamepad input devices,
 * which are reported as a normalized 'Standard Gamepad' as it is specified
 * by the W3C Gamepad API at: https://w3c.github.io/gamepad/#remapping
 */
extern const struct wl_interface zcr_gamepad_v1_interface;

/**
 * @ingroup iface_zcr_gaming_input_v1
 * @struct zcr_gaming_input_v1_interface
 */
struct zcr_gaming_input_v1_interface {
	/**
	 * get gamepad device assigned to seat
	 *
	 * Create gamepad object. See zcr_gamepad_v1 interface for
	 * details.
	 */
	void (*get_gamepad)(struct wl_client *client,
			    struct wl_resource *resource,
			    uint32_t id,
			    struct wl_resource *seat);
};


/**
 * @ingroup iface_zcr_gaming_input_v1
 */
#define ZCR_GAMING_INPUT_V1_GET_GAMEPAD_SINCE_VERSION 1

#ifndef ZCR_GAMEPAD_V1_GAMEPAD_STATE_ENUM
#define ZCR_GAMEPAD_V1_GAMEPAD_STATE_ENUM
/**
 * @ingroup iface_zcr_gamepad_v1
 * connection state
 */
enum zcr_gamepad_v1_gamepad_state {
	/**
	 * no gamepads are connected or on.
	 */
	ZCR_GAMEPAD_V1_GAMEPAD_STATE_OFF = 0,
	/**
	 * at least one gamepad is connected.
	 */
	ZCR_GAMEPAD_V1_GAMEPAD_STATE_ON = 1,
};
#endif /* ZCR_GAMEPAD_V1_GAMEPAD_STATE_ENUM */

#ifndef ZCR_GAMEPAD_V1_BUTTON_STATE_ENUM
#define ZCR_GAMEPAD_V1_BUTTON_STATE_ENUM
/**
 * @ingroup iface_zcr_gamepad_v1
 * physical button state
 *
 * Describes the physical state of a button that produced the button
 * event.
 */
enum zcr_gamepad_v1_button_state {
	/**
	 * the button is not pressed
	 */
	ZCR_GAMEPAD_V1_BUTTON_STATE_RELEASED = 0,
	/**
	 * the button is pressed
	 */
	ZCR_GAMEPAD_V1_BUTTON_STATE_PRESSED = 1,
};
#endif /* ZCR_GAMEPAD_V1_BUTTON_STATE_ENUM */

/**
 * @ingroup iface_zcr_gamepad_v1
 * @struct zcr_gamepad_v1_interface
 */
struct zcr_gamepad_v1_interface {
	/**
	 * destroy gamepad object
	 *
	 * 
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};

#define ZCR_GAMEPAD_V1_STATE_CHANGE 0
#define ZCR_GAMEPAD_V1_AXIS 1
#define ZCR_GAMEPAD_V1_BUTTON 2
#define ZCR_GAMEPAD_V1_FRAME 3

/**
 * @ingroup iface_zcr_gamepad_v1
 */
#define ZCR_GAMEPAD_V1_STATE_CHANGE_SINCE_VERSION 1
/**
 * @ingroup iface_zcr_gamepad_v1
 */
#define ZCR_GAMEPAD_V1_AXIS_SINCE_VERSION 1
/**
 * @ingroup iface_zcr_gamepad_v1
 */
#define ZCR_GAMEPAD_V1_BUTTON_SINCE_VERSION 1
/**
 * @ingroup iface_zcr_gamepad_v1
 */
#define ZCR_GAMEPAD_V1_FRAME_SINCE_VERSION 1

/**
 * @ingroup iface_zcr_gamepad_v1
 */
#define ZCR_GAMEPAD_V1_DESTROY_SINCE_VERSION 1

/**
 * @ingroup iface_zcr_gamepad_v1
 * Sends an state_change event to the client owning the resource.
 * @param resource_ The client's resource
 * @param state new state
 */
static inline void
zcr_gamepad_v1_send_state_change(struct wl_resource *resource_, uint32_t state)
{
	wl_resource_post_event(resource_, ZCR_GAMEPAD_V1_STATE_CHANGE, state);
}

/**
 * @ingroup iface_zcr_gamepad_v1
 * Sends an axis event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param axis axis that produced this event
 * @param value new value of axis
 */
static inline void
zcr_gamepad_v1_send_axis(struct wl_resource *resource_, uint32_t time, uint32_t axis, wl_fixed_t value)
{
	wl_resource_post_event(resource_, ZCR_GAMEPAD_V1_AXIS, time, axis, value);
}

/**
 * @ingroup iface_zcr_gamepad_v1
 * Sends an button event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param button id of button
 * @param state digital state of the button
 * @param analog analog value of the button
 */
static inline void
zcr_gamepad_v1_send_button(struct wl_resource *resource_, uint32_t time, uint32_t button, uint32_t state, wl_fixed_t analog)
{
	wl_resource_post_event(resource_, ZCR_GAMEPAD_V1_BUTTON, time, button, state, analog);
}

/**
 * @ingroup iface_zcr_gamepad_v1
 * Sends an frame event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 */
static inline void
zcr_gamepad_v1_send_frame(struct wl_resource *resource_, uint32_t time)
{
	wl_resource_post_event(resource_, ZCR_GAMEPAD_V1_FRAME, time);
}

#ifdef  __cplusplus
}
#endif

#endif
