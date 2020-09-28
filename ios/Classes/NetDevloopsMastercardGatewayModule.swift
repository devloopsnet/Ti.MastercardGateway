//
//  NetDevloopsMastercardGatewayModule.swift
//  Ti.MastercardGateway
//
//  Created by Abdullah Al-Faqeir
//  Copyright (c) 2020 Your Company. All rights reserved.
//

import UIKit
import TitaniumKit
import MPGSDK

@objc(NetDevloopsMastercardGatewayModule)
class NetDevloopsMastercardGatewayModule: TiModule {
    
    private var gateway:Gateway? = nil
    
    public var apiVersion:Int? = nil
    
    func moduleGUID() -> String {
        return "1f0eb513-9895-47de-bdaa-7ff85d44098a"
    }
    
    override func moduleId() -> String! {
        return "net.devloops.mastercard.gateway"
    }
    
    override func startup() {
        super.startup()
    }
    
    @objc(initialize:)
    func initialize(arguments: Array<Any>?) -> String? {
        guard let arguments = arguments, let params = arguments[0] as? [String: Any] else { fatalError("Invalid parameters sents") }
        let stringRegion = params["region"] as? String
        let merchantId = params["merchantId"] as? String
        var region:MPGSDK.GatewayRegion? = nil
        switch stringRegion {
        case "asiaPacific":
            region = GatewayRegion.asiaPacific
            break
        case "europe":
            region = GatewayRegion.europe
            break
        case "northAmerica":
            region = GatewayRegion.northAmerica
            break
        case "mtf":
            region = GatewayRegion.mtf
            break
        case "india":
            region = GatewayRegion.india
            break
        case "china":
            region = GatewayRegion.china
            break
        default:
            debugPrint("Invalid region (\(stringRegion ?? "Not Set"))")
            return "Invalid region (\(stringRegion ?? "Not Set"))"
        }
        self.gateway = Gateway(region: region!, merchantId: merchantId!)
        return "OK"
    }
    
    @objc(updateSessionWithCard:)
    func updateSessionWithCard(arguments: Array<Any>?){
        if(gateway==nil){
            debugPrint("You must call initialize() methods before calling updateSession()")
            return;
        }
        guard
            let arguments = arguments,
            let params = arguments[0] as? [String: Any],
            let callback = arguments[1] as? KrollCallback
        else {
            fatalError("Invalid parameters sents")
        }
        var request = GatewayMap()
        let sessionId:String? = params["sessionId"] as? String
        let apiVersion:String? = params["apiVersion"] as? String
        
        self.apiVersion = Int(apiVersion ?? "0")
        
        request[at: "sourceOfFunds.provided.card.nameOnCard"] = params["nameOnCard"] as? String
        request[at: "sourceOfFunds.provided.card.number"] = params["number"] as? String
        request[at: "sourceOfFunds.provided.card.securityCode"] = params["securityCode"] as? String
        request[at: "sourceOfFunds.provided.card.expiry.month"] = params["expiryMonth"] as? String
        request[at: "sourceOfFunds.provided.card.expiry.year"] = params["expiryYear"] as? String
        
        gateway!.updateSession(sessionId!, apiVersion: apiVersion!, payload: request) { (result) in
            switch result {
            case .success(let response):
                callback.call([
                    [
                        "success":true,
                        "response":response.description,
                        "params":[
                            "sessionId":params["sessionId"] as? String,
                            "apiVersion":params["apiVersion"] as? String,
                            "nameOnCard":params["nameOnCard"] as? String,
                            "number":params["number"] as? String,
                            "securityCode":params["securityCode"] as? String,
                            "expiryMonth":params["expiryMonth"] as? String,
                            "expiryYear":params["expiryYear"] as? String,
                        ]
                    ]
                ], thisObject: self)
            case .error(let error):
                callback.call([
                    [
                        "success":false,
                        "response":error.localizedDescription,
                        "params":[
                            "sessionId":params["sessionId"] as? String,
                            "apiVersion":params["apiVersion"] as? String,
                            "nameOnCard":params["nameOnCard"] as? String,
                            "number":params["number"] as? String,
                            "securityCode":params["securityCode"] as? String,
                            "expiryMonth":params["expiryMonth"] as? String,
                            "expiryYear":params["expiryYear"] as? String,
                        ]
                    ]
                ], thisObject: self)
            }
        }
    }
    
    @objc(updateSessionWithToken:)
    func updateSessionWithToken(arguments: Array<Any>?){
        if(gateway==nil){
            debugPrint("You must call initialize() methods before calling updateSession()")
            return;
        }
        guard
            let arguments = arguments,
            let params = arguments[0] as? [String: Any],
            let callback = arguments[1] as? KrollCallback
        else {
            fatalError("Invalid parameters sents")
        }
        var request = GatewayMap()
        let sessionId:String? = params["sessionId"] as? String
        let apiVersion:String? = params["apiVersion"] as? String
        
        self.apiVersion = Int(apiVersion ?? "0")
        
        request[at: "sourceOfFunds.provided.card.devicePayment.paymentToken"] = params["paymentToken"] as? String
        
        gateway!.updateSession(sessionId!, apiVersion: apiVersion!, payload: request) { (result) in
            switch result {
            case .success(let response):
                callback.call([
                    [
                        "success":true,
                        "response":response.dictionary,
                        "params":[
                            "sessionId":params["sessionId"] as? String,
                            "apiVersion":params["apiVersion"] as? String,
                            "paymentToken":params["paymentToken"] as? String,
                        ]
                    ]
                ], thisObject: self)
            case .error(let error):
                callback.call([
                    [
                        "success":false,
                        "response":error,
                        "params":[
                            "sessionId":params["sessionId"] as? String,
                            "apiVersion":params["apiVersion"] as? String,
                            "paymentToken":params["paymentToken"] as? String,
                        ]
                    ]
                ], thisObject: self)
            }
        }
    }
    
    @objc(start3DSecure:)
    func start3DSecure(arguments: Array<Any>?){
        if(gateway==nil){
            debugPrint("You must call initialize() methods before calling start3DSecure()")
            return;
        }
        guard let arguments = arguments, let params = arguments[0] as? [String: Any] else { fatalError("Invalid parameters sents") }
        let threeDSecureView = Gateway3DSecureViewController(nibName: nil, bundle: nil)
        
        if #available(iOS 13, *) {
            threeDSecureView.modalPresentationStyle = .fullScreen
        }
        
        TiApp.controller()?.topPresentedController()?.present(threeDSecureView, animated: true, completion: nil)
        
        if let title = params["title"] as? String{
            threeDSecureView.title = title
        }
        if let tintColor = params["tintColor"] as? String{
            threeDSecureView.navBar.tintColor = TiUtils.colorValue(tintColor)?.color
        }
        let html:String? = params["html"] as? String
        threeDSecureView.authenticatePayer(htmlBodyContent: html!, handler: handle3DS(authView:result:))
    }
    
    
    
    func handle3DS(authView: Gateway3DSecureViewController, result: Gateway3DSecureResult) {
        authView.dismiss(animated: true, completion: { [self] in
            switch result {
            case .error(gateway3DSecureError: let error):
                self.fireEvent("3ds_error",with: [
                    "error":"3DS Authentication Failed",
                    "error_description":error.localizedDescription,
                ])
            case .completed(gatewayResult: let response):
                // check for version 46 and earlier api authentication failures and then version 47+ failures
                if self.apiVersion! <= 46, let status = response[at: "3DSecure.summaryStatus"] as? String , status == "AUTHENTICATION_FAILED" {
                    self.fireEvent("threeds_error",with: [
                        "error":"3DS Authentication Failed",
                        "status":"AUTHENTICATION_FAILED",
                        "response":response.dictionary
                    ])
                } else if let status = response[at: "response.gatewayRecommendation"] as? String, status == "DO_NOT_PROCEED"  {
                    self.fireEvent("threeds_error",with: [
                        "error":"3DS Authentication Failed",
                        "status":"DO_NOT_PROCEED",
                        "response":response.dictionary
                    ])
                } else {
                    self.fireEvent("threeds_success", with:[
                        "response":response.dictionary
                    ])
                }
            default:
                self.fireEvent("threeds_error",with: [
                    "error":"3DS Authentication Cancelled"
                ])
            }
        })
    }
    
}
