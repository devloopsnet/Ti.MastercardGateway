/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "net.devloops.mastercard.gateway.TiMastercardGatewayModule.h"

#include "JSException.h"
#include "TypeConverter.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "TiMastercardGatewayModule"

using namespace v8;

namespace net {
namespace devloops {
namespace mastercard {
namespace gateway {


Persistent<FunctionTemplate> TiMastercardGatewayModule::proxyTemplate;
Persistent<Object> TiMastercardGatewayModule::moduleInstance;
jclass TiMastercardGatewayModule::javaClass = NULL;

TiMastercardGatewayModule::TiMastercardGatewayModule() : titanium::Proxy()
{
}

void TiMastercardGatewayModule::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "TiMastercardGateway"); // use symbol over string for efficiency
	MaybeLocal<Object> maybeInstance = constructor->NewInstance(context);
	Local<Object> instance;
	if (!maybeInstance.ToLocal(&instance)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}
	exports->Set(context, nameSymbol, instance);
	moduleInstance.Reset(isolate, instance);
}

void TiMastercardGatewayModule::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}
	if (!moduleInstance.IsEmpty()) {
	    moduleInstance.Reset();
	}

	titanium::KrollModule::dispose(isolate);
}

Local<FunctionTemplate> TiMastercardGatewayModule::getProxyTemplate(v8::Isolate* isolate)
{
	Local<Context> context = isolate->GetCurrentContext();
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "TiMastercardGatewayModule::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("net/devloops/mastercard/gateway/TiMastercardGatewayModule");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "TiMastercardGateway");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		isolate,
		titanium::KrollModule::getProxyTemplate(isolate),
		javaClass,
		nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate), FunctionTemplate::New(isolate, titanium::Proxy::inherit<TiMastercardGatewayModule>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "updateSessionWithCard", TiMastercardGatewayModule::updateSessionWithCard);
	titanium::SetProtoMethod(isolate, t, "initialize", TiMastercardGatewayModule::initialize);
	titanium::SetProtoMethod(isolate, t, "start3DSecure", TiMastercardGatewayModule::start3DSecure);
	titanium::SetProtoMethod(isolate, t, "updateSessionWithToken", TiMastercardGatewayModule::updateSessionWithToken);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

Local<FunctionTemplate> TiMastercardGatewayModule::getProxyTemplate(v8::Local<v8::Context> context)
{
	return getProxyTemplate(context->GetIsolate());
}

// Methods --------------------------------------------------------------------
void TiMastercardGatewayModule::updateSessionWithCard(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "updateSessionWithCard()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TiMastercardGatewayModule::javaClass, "updateSessionWithCard", "(Lorg/appcelerator/kroll/KrollDict;Lorg/appcelerator/kroll/KrollFunction;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'updateSessionWithCard' with signature '(Lorg/appcelerator/kroll/KrollDict;Lorg/appcelerator/kroll/KrollFunction;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 2) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "updateSessionWithCard: Invalid number of arguments. Expected 2 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[2];




	bool isNew_0;
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	bool isNew_1;
	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_1, &isNew_1);
	} else {
		jArguments[1].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


			if (isNew_1) {
				env->DeleteLocalRef(jArguments[1].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void TiMastercardGatewayModule::initialize(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "initialize()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TiMastercardGatewayModule::javaClass, "initialize", "(Lorg/appcelerator/kroll/KrollDict;)Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'initialize' with signature '(Lorg/appcelerator/kroll/KrollDict;)Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "initialize: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void TiMastercardGatewayModule::start3DSecure(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "start3DSecure()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TiMastercardGatewayModule::javaClass, "start3DSecure", "(Lorg/appcelerator/kroll/KrollDict;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'start3DSecure' with signature '(Lorg/appcelerator/kroll/KrollDict;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "start3DSecure: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void TiMastercardGatewayModule::updateSessionWithToken(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "updateSessionWithToken()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(TiMastercardGatewayModule::javaClass, "updateSessionWithToken", "(Lorg/appcelerator/kroll/KrollDict;Lorg/appcelerator/kroll/KrollFunction;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'updateSessionWithToken' with signature '(Lorg/appcelerator/kroll/KrollDict;Lorg/appcelerator/kroll/KrollFunction;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 2) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "updateSessionWithToken: Invalid number of arguments. Expected 2 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[2];




	bool isNew_0;
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	bool isNew_1;
	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_1, &isNew_1);
	} else {
		jArguments[1].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


			if (isNew_1) {
				env->DeleteLocalRef(jArguments[1].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}

// Dynamic property accessors -------------------------------------------------


} // gateway
} // mastercard
} // devloops
} // net
