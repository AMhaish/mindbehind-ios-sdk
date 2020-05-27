Pod::Spec.new do |s|
  s.name                  = "MindBehind"
  s.version               = "1.0.0"
  s.summary               = "Mindbehind IOS let you integrate a chat widget inside IOS application and link it with IOS channel in Mindbehind platform."
  s.homepage              = "https://www.mindbehind.com"
  s.author                = { "Mindbehind" => "support@mindbehind.com" }
  s.license               = { :type => "Commercial", :text => "https://www.mindbehind.com/terms-and-conditions" }
  s.source                   = { :path => '.' }
  s.source_files          = "MindBehind.framework/Headers/MindBehind.h", "MindBehind.framework/Headers/MBCSettings.h", "MindBehind.framework/Headers/MBCUser.h", "MindBehind.framework/Headers/MBCConversation.h", "MindBehind.framework/Headers/MBCMessage.h", "MindBehind.framework/Headers/MBCMessageAction.h", "MindBehind.framework/Headers/MBCConversationActivity.h", "MindBehind.framework/Headers/MBCCoordinates.h"
  s.preserve_paths        = "MindBehind.framework/*"
  s.module_map            = "MindBehind.framework/Modules/module.modulemap"
  s.frameworks            = "MindBehind", "CoreText", "SystemConfiguration", "CoreTelephony", "Foundation", "CoreGraphics", "UIKit", "QuartzCore", "AssetsLibrary", "Photos", "AVFoundation", "CFNetwork"
  s.library               = "icucore"
  s.vendored_frameworks   = "MindBehind.framework"
  s.requires_arc          = true
  s.platform              = :ios
  s.ios.deployment_target = '8.0'
end
