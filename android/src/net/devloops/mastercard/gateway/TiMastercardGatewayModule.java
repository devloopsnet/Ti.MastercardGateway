/**
 * This file was auto-generated by the Titanium Module SDK helper for Android
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
package net.devloops.mastercard.gateway;

import android.app.Activity;
import android.content.Intent;

import com.mastercard.gateway.android.sdk.Gateway;
import com.mastercard.gateway.android.sdk.Gateway3DSecureCallback;
import com.mastercard.gateway.android.sdk.GatewayCallback;
import com.mastercard.gateway.android.sdk.GatewayMap;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.TiConfig;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.util.TiActivityResultHandler;
import org.appcelerator.titanium.util.TiActivitySupport;

/**
 * @author Abdullah Al-Faqeir <abdullah@devloops.net>
 * @company Devloops LLC
 */
@Kroll.module(name = "TiMastercardGateway", id = "net.devloops.mastercard.gateway")
public class TiMastercardGatewayModule extends KrollModule implements TiActivityResultHandler {

    private static final String LCAT = "TiMastercardGatewayModule";
    private static final boolean DBG = TiConfig.LOGD;

    static final int REQUEST_3D_SECURE = 10000;

    private Gateway gateway;

    public int apiVersion;

    public TiMastercardGatewayModule() {
        super();
    }

    // Methods
    @Kroll.method(runOnUiThread = true)
    public String initialize(@Kroll.argument KrollDict config) {
        String stringRegion = (String) config.get("region");
        String merchantId = (String) config.get("merchantId");
        Gateway.Region region;
        switch (stringRegion) {
            case "asiaPacific":
                region = Gateway.Region.ASIA_PACIFIC;
                break;
            case "europe":
                region = Gateway.Region.EUROPE;
                break;
            case "northAmerica":
                region = Gateway.Region.NORTH_AMERICA;
                break;
            case "mtf":
                region = Gateway.Region.MTF;
                break;
            case "india":
                region = Gateway.Region.INDIA;
                break;
            case "china":
                region = Gateway.Region.CHINA;
                break;
            default:
                return "Invalid region (" + stringRegion + ")";
        }
        gateway = new Gateway();
        gateway.setMerchantId(merchantId);
        gateway.setRegion(region);
        return "OK";
    }

    @Kroll.method(runOnUiThread = true)
    public void updateSessionWithCard(@Kroll.argument KrollDict cardDetails, final KrollFunction callback) {
        if (gateway == null) {
            System.out.println("You must call initialize() methods before calling updateSession()");
            return;
        }
        String sessionId = (String) cardDetails.get("sessionId");
        String apiVersion = (String) cardDetails.get("apiVersion");
        this.apiVersion = Integer.parseInt(apiVersion);
        GatewayMap request = new GatewayMap()
                .set("sourceOfFunds.provided.card.nameOnCard", (String) cardDetails.get("nameOnCard"))
                .set("sourceOfFunds.provided.card.number", (String) cardDetails.get("number"))
                .set("sourceOfFunds.provided.card.securityCode", (String) cardDetails.get("securityCode"))
                .set("sourceOfFunds.provided.card.expiry.month", (String) cardDetails.get("expiryMonth"))
                .set("sourceOfFunds.provided.card.expiry.year", (String) cardDetails.get("expiryYear"));

        gateway.updateSession(sessionId, apiVersion, request, new GatewayCallback() {
            @Override
            public void onSuccess(GatewayMap response) {
                KrollDict dict = new KrollDict();
                dict.put("success", true);
                dict.put("response", response);
                callback.callAsync(getKrollObject(), dict);
            }

            @Override
            public void onError(Throwable throwable) {
                KrollDict dict = new KrollDict();
                dict.put("success", false);
                dict.put("response", throwable.getMessage());
                callback.callAsync(getKrollObject(), dict);
            }
        });
    }

    @Kroll.method(runOnUiThread = true)
    public void updateSessionWithToken(@Kroll.argument KrollDict cardDetails, final KrollFunction callback) {
        if (gateway == null) {
            System.out.println("You must call initialize() methods before calling updateSession()");
            return;
        }
        String sessionId = (String) cardDetails.get("sessionId");
        String apiVersion = (String) cardDetails.get("apiVersion");
        GatewayMap request = new GatewayMap()
                .set("sourceOfFunds.provided.card.devicePayment.paymentToken", (String) cardDetails.get("paymentToken"));
        this.apiVersion = Integer.parseInt(apiVersion);
        gateway.updateSession(sessionId, apiVersion, request, new GatewayCallback() {
            @Override
            public void onSuccess(GatewayMap response) {
                KrollDict dict = new KrollDict();
                dict.put("success", true);
                dict.put("response", response.toString());
                callback.callAsync(getKrollObject(), dict);
            }

            @Override
            public void onError(Throwable throwable) {
                KrollDict dict = new KrollDict();
                dict.put("success", false);
                dict.put("response", throwable.getMessage());
                callback.callAsync(getKrollObject(), dict);
            }
        });
    }

    @Kroll.method(runOnUiThread = true)
    public void start3DSecure(@Kroll.argument KrollDict threeDSecure) {
        if (gateway == null) {
            System.out.println("You must call initialize() methods before calling updateSession()");
            return;
        }
        String html = (String) threeDSecure.get("html");
        Intent intent = new Intent(TiApplication.getInstance().getCurrentActivity(), TiMastercardGateway3DSecureActivity.class);
        intent.putExtra(TiMastercardGateway3DSecureActivity.EXTRA_HTML, html); // required
        if (threeDSecure.get("title") != null) {
            intent.putExtra(TiMastercardGateway3DSecureActivity.EXTRA_TITLE, (String) threeDSecure.get("title"));
        }
        try {
            Activity activity = TiApplication.getAppCurrentActivity();
            TiActivitySupport activitySupport = (TiActivitySupport) activity;
            activitySupport.launchActivityForResult(intent, REQUEST_3D_SECURE, this);
        } catch (Exception e) {
            for (int i = 0; i < e.getStackTrace().length; i++)
                System.out.println(e.getStackTrace()[i]);
        }
    }

    @Override
    public void onResult(Activity activity, int requestCode, int resultCode, Intent data) {
        Gateway.handle3DSecureResult(requestCode, resultCode, data, new ThreeDSecureCallback());
    }

    @Override
    public void onError(Activity activity, int requestCode, Exception e) {
        KrollDict dict = new KrollDict();
        dict.put("error", "3DS Authentication Failed");
        fireEvent("3ds_Error", dict);
    }

    class ThreeDSecureCallback implements Gateway3DSecureCallback {

        @Override
        public void on3DSecureCancel() {
            KrollDict dict = new KrollDict();
            dict.put("error", "3DS Authentication Cancelled");
            dict.put("error_description", "3DS Authentication Cancelled");
            fireEvent("threeds_error", dict);
        }

        @Override
        public void on3DSecureComplete(GatewayMap result) {

            if (apiVersion <= 46) {
                if ("AUTHENTICATION_FAILED".equalsIgnoreCase((String) result.get("3DSecure.summaryStatus"))) {
                    KrollDict dict = new KrollDict();
                    dict.put("error", "3DS Authentication Failed");
                    dict.put("status", "AUTHENTICATION_FAILED");
                    dict.put("response", result);
                    fireEvent("threeds_error", dict);
                    return;
                }
            } else { // version >= 47
                if ("DO_NOT_PROCEED".equalsIgnoreCase((String) result.get("response.gatewayRecommendation"))) {
                    KrollDict dict = new KrollDict();
                    dict.put("error", "3DS Authentication Failed");
                    dict.put("status", "DO_NOT_PROCEED");
                    dict.put("response", result);
                    fireEvent("threeds_error", dict);
                    return;
                }
            }
            KrollDict dict = new KrollDict();
            dict.put("response", result);
            fireEvent("threeds_success", dict);
        }

    }
}
