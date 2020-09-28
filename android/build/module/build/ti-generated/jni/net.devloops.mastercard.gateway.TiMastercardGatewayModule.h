/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include "Proxy.h"

namespace net {
namespace devloops {
namespace mastercard {
namespace gateway {

class TiMastercardGatewayModule : public titanium::Proxy
{
public:
	explicit TiMastercardGatewayModule();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Local<v8::Context>);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;
	static v8::Persistent<v8::Object> moduleInstance;

	// Methods -----------------------------------------------------------
	static void updateSessionWithCard(const v8::FunctionCallbackInfo<v8::Value>&);
	static void initialize(const v8::FunctionCallbackInfo<v8::Value>&);
	static void start3DSecure(const v8::FunctionCallbackInfo<v8::Value>&);
	static void updateSessionWithToken(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------

};

} // gateway
} // mastercard
} // devloops
} // net
