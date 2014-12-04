//
//  SPDYDefinitions.h
//  SPDY
//
//  Copyright (c) 2014 Twitter, Inc. All rights reserved.
//  Licensed under the Apache License v2.0
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Created by Michael Schore and Jeffrey Pinner.
//

#import "SPDYError.h"

typedef enum : uint32_t {
    SPDY_SYN_STREAM_FRAME = 1,
    SPDY_SYN_REPLY_FRAME,
    SPDY_RST_STREAM_FRAME,
    SPDY_SETTINGS_FRAME,
    SPDY_NOOP_FRAME,
    SPDY_PING_FRAME,
    SPDY_GOAWAY_FRAME,
    SPDY_HEADERS_FRAME,
    SPDY_WINDOW_UPDATE_FRAME,
    SPDY_CREDENTIAL_FRAME
} SPDYControlFrameType;

typedef enum : uint32_t {
    SPDY_STREAM_PROTOCOL_ERROR = 1,
    SPDY_STREAM_INVALID_STREAM,
    SPDY_STREAM_REFUSED_STREAM,
    SPDY_STREAM_UNSUPPORTED_VERSION,
    SPDY_STREAM_CANCEL,
    SPDY_STREAM_INTERNAL_ERROR,
    SPDY_STREAM_FLOW_CONTROL_ERROR,
    SPDY_STREAM_STREAM_IN_USE,
    SPDY_STREAM_STREAM_ALREADY_CLOSED,
    SPDY_STREAM_INVALID_CREDENTIALS,
    SPDY_STREAM_FRAME_TOO_LARGE
} SPDYStreamStatus;

typedef enum : uint32_t {
    SPDY_SESSION_OK = 0,
    SPDY_SESSION_PROTOCOL_ERROR,
    SPDY_SESSION_INTERNAL_ERROR
} SPDYSessionStatus;

typedef enum : uint32_t {
    _SPDY_SETTINGS_RANGE_START = 0,
    SPDY_SETTINGS_MINOR_VERSION = _SPDY_SETTINGS_RANGE_START,
    SPDY_SETTINGS_UPLOAD_BANDWIDTH,
    SPDY_SETTINGS_DOWNLOAD_BANDWIDTH,
    SPDY_SETTINGS_ROUND_TRIP_TIME,
    SPDY_SETTINGS_MAX_CONCURRENT_STREAMS,
    SPDY_SETTINGS_CURRENT_CWND,
    SPDY_SETTINGS_DOWNLOAD_RETRANS_RATE,
    SPDY_SETTINGS_INITIAL_WINDOW_SIZE,
    SPDY_SETTINGS_CLIENT_CERTIFICATE_VECTOR_SIZE,
    _SPDY_SETTINGS_RANGE_END,
} SPDYSettingsId;

#define SPDY_SETTINGS_LENGTH _SPDY_SETTINGS_RANGE_END
#define SPDY_SETTINGS_ITERATOR(i) for (SPDYSettingsId i = _SPDY_SETTINGS_RANGE_START; i < _SPDY_SETTINGS_RANGE_END; i++)

typedef struct {
    bool set;
    uint8_t flags;
    int32_t value;
} SPDYSettings;

typedef uint32_t SPDYPingId;
typedef uint32_t SPDYStreamId;

static const SPDYStreamId kSPDYSessionStreamId = 0;

static const uint8_t SPDY_FLAG_FIN            = 0x01;
static const uint8_t SPDY_FLAG_UNIDIRECTIONAL = 0x02;

static const uint8_t SPDY_DATA_FLAG_FIN = 0x01;

static const uint8_t SPDY_SETTINGS_FLAG_CLEAR_SETTINGS = 0x01;
static const uint8_t SPDY_SETTINGS_FLAG_PERSIST_VALUE  = 0x01;
static const uint8_t SPDY_SETTINGS_FLAG_PERSISTED      = 0x02;

#define SPDY_STREAM_ERROR(CODE, MESSAGE) \
[[NSError alloc] initWithDomain:SPDYStreamErrorDomain code:CODE userInfo:@{ NSLocalizedDescriptionKey: MESSAGE}]

#define SPDY_SESSION_ERROR(CODE, MESSAGE) \
[[NSError alloc] initWithDomain:SPDYSessionErrorDomain code:CODE userInfo:@{ NSLocalizedDescriptionKey: MESSAGE}]

#define SPDY_SOCKET_ERROR(CODE, MESSAGE) \
[[NSError alloc] initWithDomain:SPDYSocketErrorDomain code:CODE userInfo:@{ NSLocalizedDescriptionKey: MESSAGE}]

#define SPDY_CODEC_ERROR(CODE, MESSAGE) \
[[NSError alloc] initWithDomain:SPDYCodecErrorDomain code:CODE userInfo:@{ NSLocalizedDescriptionKey: MESSAGE}]
