
Pod::Spec.new do |s|

    s.name         = "Ti.MastercardGateway"
    s.version      = "1.0.0"
    s.summary      = "The Ti.MastercardGateway Titanium module."
  
    s.description  = <<-DESC
                     The Ti.MastercardGateway Titanium module.
                     DESC
  
   s.homepage     = "https://example.com"
    s.license      = { :type => "Apache 2", :file => "LICENSE" }
    s.author       = 'Author'
  
    s.platform     = :ios
    s.ios.deployment_target = '8.0'
  
    s.source       = { :git => "https://github.com/<organization>/<repository>.git" }
    
    s.ios.weak_frameworks = 'UIKit', 'Foundation'

    s.ios.dependency 'TitaniumKit'
  
    s.public_header_files = 'Classes/*.h'
    s.source_files = 'Classes/*.{h,m,swift}'
  end