# Installation guide locally

To add the MindBehind.framework library to your XCode project, follow the steps below to install the framework using CocoaPods

1. First, install [CocoaPods](https://cocoapods.org/) if it isn't already

```bash
gem install cocoapods
```

2. Add the MindBehind dependency to your [Podfile](https://guides.cocoapods.org/using/the-podfile.html), you will put your pod file inside your XCode project and you should reference the project using its exact name in 'YourApp'

```ruby
target 'YourApp' do
    pod 'MindBehind'
end
```

3. Install the pod

```bash
pod install
```

4. Open the generated `.xcworkspace` file and add the following keys to your app's Info.plist file (replacing the values if desired):

```xml
<key>NSPhotoLibraryUsageDescription</key>
<string>${PRODUCT_NAME} will read your photo library to gather additional information</string>
<key>NSPhotoLibraryAddUsageDescription</key>
<string>${PRODUCT_NAME} will write to your photo library to gather additional information</string>
<key>NSCameraUsageDescription</key>
<string>${PRODUCT_NAME} will use your camera to gather additional information</string>
```

5. Start using the framework in your code.

Objective-C:

```objc
#import <MindBehind/MindBehind.h>

[MindBehind initWithSettings:[MBCSettings settingsWithIntegrationId:@"YOUR_INTEGRATION_ID"] completionHandler:^(NSError * _Nullable error, NSDictionary * _Nullable userInfo) {
    // Your code after init is complete
}];
```

Swift:

```swift
import MindBehind

MindBehind.initWith(MBCSettings(integrationId: "YOUR_INTEGRATION_ID")) { (error: Error?, userInfo: [AnyHashable : Any]?) in
    // Your code after init is complete
}
```
