//
//  SPDYError.h
//  SPDY
//
//  Copyright (c) 2014 Twitter, Inc. All rights reserved.
//  Licensed under the Apache License v2.0
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Created by Michael Schore and Jeffrey Pinner.
//

extern NSString *const SPDYStreamErrorDomain;
extern NSString *const SPDYSessionErrorDomain;
extern NSString *const SPDYCodecErrorDomain;
extern NSString *const SPDYSocketErrorDomain;

// These errors map one-to-one with the status code in a RST_STREAM message.
typedef enum {
    SPDYStreamProtocolError = 1,
    SPDYStreamInvalidStream,
    SPDYStreamRefusedStream,
    SPDYStreamUnsupportedVersion,
    SPDYStreamCancel,
    SPDYStreamInternalError,
    SPDYStreamFlowControlError,
    SPDYStreamStreamInUse,
    SPDYStreamStreamAlreadyClosed,
    SPDYStreamInvalidCredentials,
    SPDYStreamFrameTooLarge
} SPDYStreamError;

// These errors map one-to-one with the status code in a GOAWAY message.
typedef enum {
    SPDYSessionProtocolError = 1,
    SPDYSessionInternalError
} SPDYSessionError;

typedef enum {
    SDPYHeaderBlockEncodingError = 1,
    SDPYHeaderBlockDecodingError
} SPDYCodecError;

typedef enum {
    SPDYSocketCFSocketError = kCFSocketError, // From CFSocketError enum.
    SPDYSocketConnectCanceled = 1,            // socketWillConnect: returned NO.
    SPDYSocketConnectTimeout,
    SPDYSocketReadTimeout,
    SPDYSocketWriteTimeout,
    SPDYSocketTLSVerificationFailed,
    SPDYSocketTransportError
} SPDYSocketError;
