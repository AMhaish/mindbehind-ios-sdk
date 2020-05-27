//
//  MindBehind.h
//  MindBehind
//
//  version : 2.0.0

#import <Foundation/Foundation.h>
#import "MBCConversation.h"
#import "MBCSettings.h"
#import "MBCUser.h"
#import "MBCParticipant.h"

NS_ASSUME_NONNULL_BEGIN
@protocol UNUserNotificationCenterDelegate;

#define MINDBEHIND_VERSION @"2.0.0"
#define VENDOR_ID @"mindBehind"

FOUNDATION_EXPORT double MindBehindVersionNumber;
FOUNDATION_EXPORT const unsigned char MindBehindVersionString[];

/**
 *  @abstract User info dictionary key to determine the origin of a push notification.
 *
 *  @discussion Push notifications that originate from MindBehind will have a non-nil value for this key.
 *
 *  `BOOL isMindBehindNotification = userInfo[MBCPushNotificationIdentifier] != nil`
 */
extern NSString* const MBCPushNotificationIdentifier;

/**
 *  @abstract User info dictionary key for an MBCUser after a successful call to +login:jwt:completionHandler:
 *
 *  @see MBCUser
 *  @see MBCLoginDidCompleteNotification
 *  @see +login:jwt:completionHandler:
 */
extern NSString* const MBCUserIdentifier;

/**
 *  @abstract User info dictionary key for an MBCConversation after a successful call to +startConversationWithCompletionHandler:
 *
 *  @see MBCConversation
 *  @see +startConversationWithCompletionHandler:
 */
extern NSString* const MBCConversationIdentifier;

/**
 *  @abstract User info dictionary key to determine the error code of a failed operation. Possible operations that may include this value are +initWithSettings:completionHandler:, +login:jwt:completionHandler: and +logoutWithCompletionHandler:
 *
 *  @discussion Possible values include, but are not limited to, "unauthorized", "invalid_auth", "bad_request", "unhandled_error", "invalid_app" or an empty string for connectivity errors
 *
 *  @see MBCInitializationDidFailNotification
 *  @see MBCLoginDidFailNotification
 *  @see MBCLogoutDidFailNotification
 *  @see +initWithSettings:completionHandler:
 *  @see +login:jwt:completionHandler:
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const MBCErrorCodeIdentifier;

/**
 *  @abstract User info dictionary key to determine the error description of a failed operation. Possible operations that include this value are +initWithSettings:completionHandler:, +login:jwt:completionHandler: and +logoutWithCompletionHandler:
 *
 *  @see MBCInitializationDidFailNotification
 *  @see MBCLoginDidFailNotification
 *  @see MBCLogoutDidFailNotification
 *  @see +initWithSettings:completionHandler:
 *  @see +login:jwt:completionHandler:
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const MBCErrorDescriptionIdentifier;

/**
 *  @abstract Custom error domain identifier
 */
extern NSString* const MBCErrorDomainIdentifier;

/**
 *  @abstract User info dictionary key to determine the HTTP status code of a failed operation. Possible operations that include this value are +initWithSettings:completionHandler:, +login:jwt:completionHandler: and +logoutWithCompletionHandler:
 *
 *  @discussion User info dictionary key to determine the HTTP status code of a failed operation
 *
 *  @see MBCInitializationDidFailNotification
 *  @see MBCLoginDidFailNotification
 *  @see MBCLogoutDidFailNotification
 *  @see +initWithSettings:completionHandler:
 *  @see +login:jwt:completionHandler:
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const MBCStatusCodeIdentifier;

/**
 *  @abstract Identifier for a MindBehind user notification reply action.
 *
 *  @discussion Used as the identifier for a UIUserNotificationAction on iOS 9, and a UNTextInputNotificationAction on iOS 10 and above.
 */
extern NSString* const MBCUserNotificationReplyActionIdentifier;

/**
 *  @abstract Identifier for a MindBehind user notification category.
 *
 *  @discussion Used as the identifier for a UIUserNotificationCategory on iOS 9, and a UNNotificationCategory on iOS 10 and above.
 */
extern NSString* const MBCUserNotificationReplyCategoryIdentifier;

/**
 *  @abstract Notification that fires when initialization completes successfully
 *
 *  @discussion This notification is fired each time a call to +initWithSettings:completionHandler: completes with a non-error status code.
 *
 *  @see +initWithSettings:completionHandler:
 */
extern NSString* const MBCInitializationDidCompleteNotification;

/**
 *  @abstract Notification that fires when initialization fails
 *
 *  @discussion This notification is fired each time a call to +initWithSettings:completionHandler: fails.
 *
 *  You may use this notification to know if initialization failed due to an invalid app ID, invalid JWT, or connectivity errors by inspecting the `userInfo` dictionary included with it.
 *
 *  @see MBCErrorCodeIdentifier
 *  @see MBCErrorDescriptionIdentifier
 *  @see MBCStatusCodeIdentifier
 */
extern NSString* const MBCInitializationDidFailNotification;

/**
 *  @abstract Notification that fires when +login:jwt:completionHandler: completes successfully
 *
 *  @discussion This notification is fired each time a call to +login:jwt:completionHandler: completes with a non-error status code.
 *
 *  @see +login:jwt:completionHandler:
 *  @see MBCUserIdentifier
 */
extern NSString* const MBCLoginDidCompleteNotification;

/**
 *  @abstract Notification that fires when +login:jwt:completionHandler: fails
 *
 *  @discussion This notification is fired each time a call to +login:jwt:completionHandler: fails.
 *
 *  You may use this notification to know if a call to +login:jwt:completionHandler: failed due to an invalid JWT, or connectivity errors by inspecting the `userInfo` dictionary included with it.
 *
 *  @see MBCErrorCodeIdentifier
 *  @see MBCErrorDescriptionIdentifier
 *  @see MBCStatusCodeIdentifier
 */
extern NSString* const MBCLoginDidFailNotification;

/**
 *  @abstract Notification that fires when +logoutWithCompletionHandler: completes successfully
 *
 *  @discussion This notification is fired each time a call to +logoutWithCompletionHandler: completes with a non-error status code.
 *
 *  @see +logoutWithCompletionHandler:
 */
extern NSString* const MBCLogoutDidCompleteNotification;

/**
 *  @abstract Notification that fires when a call to +logoutWithCompletionHandler: fails
 *
 *  @discussion This notification is fired when a call to +logoutWithCompletionHandler: fails
 *
 *  @see MBCErrorCodeIdentifier
 *  @see MBCErrorDescriptionIdentifier
 *  @see MBCStatusCodeIdentifier
 */
extern NSString* const MBCLogoutDidFailNotification;

/**
 *  @abstract The core class used for interacting with MindBehind. Provides methods to initialize, configure, and interact with the library.
 */
@interface MindBehind : NSObject

/**
 *  @abstract Initialize the MindBehind SDK with the provided settings.
 *
 *  @discussion This may only be called once (preferably, in application:didFinishLaunchingWithOptions:).
 *
 *  Use +settings to retrieve and modify the given settings object.
 *
 *  @see MBCSettings
 *
 *  @param settings The settings to use.
 *  @param handler An optional block to evaluate the result of the operation
 */
+(void)initWithSettings:(MBCSettings*)settings completionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))handler;

/**
 *  @abstract Accessor method for the sdk settings.
 *
 *  @discussion Use this object to update settings at run time.
 *
 *  Note: Some settings may only be configured at init time. See the MBCSettings class reference for more information.
 *
 *  @see MBCSettings
 *
 *  @return Settings object passed in +initWithSettings:completionHandler:, or nil if +initWithSettings:completionHandler: hasn't been called yet.
 */
+(nullable MBCSettings*)settings;

/**
 *  @abstract Presents the MindBehind conversation screen.
 *
 *  @discussion Uses the top-most view controller of the `UIApplicationDelegate` as the presenting view controller.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)show;

/**
 *  @abstract Presents the MindBehind conversation screen with prefilled text in the message input.
 *
 *  @discussion Uses the top-most view controller of the `UIApplicationDelegate` as the presenting view controller with prefilled text in the message input.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)showWithStartingText:(nullable NSString *)startingText;

/**
 *  @abstract Dismisses the MindBehind conversation, if shown.
 *
 *  @discussion Note: If a view controller was created and presented using `newConversationViewController`, calling this method will have no effect.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)close;

/**
 *  @abstract Destroys the MindBehind SDK
 *
 *  @discussion MindBehind is automatically terminated when the application exits. This method does not need to be called manually
 *
 */
+(void)destroy;

/**
 *  @abstract Presents the MindBehind conversation screen, using the given view controller as presenting view controller.
 *
 *  @discussion In most cases, it is better to use +show. If you need more fine-grained control over which view controller is used as presenting view controller, use this method instead.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)showConversationFromViewController:(UIViewController*)viewController;

/**
 *  @abstract Presents the MindBehind conversation screen, using the given view controller as presenting view controller with prefilled text in the message input.
 *
 *  @discussion In most cases, it is better to use +show. If you need more fine-grained control over which view controller is used as presenting view controller, use this method instead.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 */
+(void)showConversationFromViewController:(UIViewController*)viewController withStartingText:(nullable NSString *)startingText;

/**
 *  @abstract Creates and returns a MindBehind conversation view controller.
 *
 *  @discussion You may use this view controller to embed the conversation in a navigation controller, to change the modal presentation style, or display it in any way you choose.
 *
 *  A view controller created in this way is tied to the current user's conversation at creation time. If the current user changes (i.e. by calling +login:jwt:completionHandler: or +logoutWithCompletionHandler:), the view controller is invalidated and must be recreated for the new user.
 *
 *  Note: It is the responsibility of the caller to show, hide, and maintain a reference to this view controller. Calling `close` will not dismiss a view controller created in this way.
 *
 *  @return A new instance of the MindBehind conversation view controller class. Returns nil if +initWithSettings:completionHandler: hasn't been called
 */
+(nullable UIViewController*)newConversationViewController;

/**
 *  @abstract Creates and returns a MindBehind conversation view controller with prefilled text in the message input.
 *
 *  @discussion You may use this view controller to embed the conversation in a navigation controller, to change the modal presentation style, or display it in any way you choose. The message input will be prefilled with the given `startingText`
 *
 *  A view controller created in this way is tied to the current user's conversation at creation time. If the current user changes (i.e. by calling +login:jwt:completionHandler: or +logoutWithCompletionHandler:), the view controller is invalidated and must be recreated for the new user.
 *
 *  Note: It is the responsibility of the caller to show, hide, and maintain a reference to this view controller. Calling `close` will not dismiss a view controller created in this way.
 *
 *  @return A new instance of the MindBehind conversation view controller class. Returns nil if +initWithSettings:completionHandler: hasn't been called
 */
+(nullable UIViewController*)newConversationViewControllerWithStartingText:(nullable NSString *)startingText;

/**
 *  @abstract Sets the current user's first and last name to be used as a display name when sending messages.
 *
 *  @discussion This is a shortcut for -setFirstName and -setLastName on `[MBCUser currentUser]`
 *
 *  @see MBCUser
 *
 *  @param firstName The first name of the user
 *  @param lastName The last name of the user
 */
+(void)setUserFirstName:(nullable NSString*)firstName lastName:(nullable NSString*)lastName;

/**
 *  @abstract Accessor method for the current conversation.
 *
 *  @see MBCConversation
 *
 *  @return Current conversation, or nil if +initWithSettings:completionHandler: hasn't been called yet.
 */
+ (nullable MBCConversation *)conversation;

/**
 * @abstract Get a conversationById. This is an asynchronous call and requires a callback to retrieve the result.
 *
 * +initWithSettings:completionHandler: must have been called prior to calling this method.
 *
 * @see MBCConversation
 * @param conversationId the conversationId
 */
+ (void)conversationById:(NSString *)conversationId completionHandler:(nullable void(^)(NSError * _Nullable error, MBCConversation * _Nullable conversation))handler;

/**
 *  @abstract Logs in a new MindBehind user.
 *
 *  @discussion You can either use this method to transition from logged out state to logged in, or to switch the currently logged in user to a different one.
 *
 *  User login state is persisted across app launches. You must call +logoutWithCompletionHandler: to reset to anonymous mode.
 *
 *  +initWithSettings:completionHandler: must have been called prior to calling this method.
 *
 *  You may not call login while the conversation screen is shown. Doing so will result in a no-op.
 *
 *  @param userId The distinct id of the user to login. Must not be nil.
 *  @param jwt jwt used to prove the origin of the login request. Must not be nil.
 */
+(void)login:(NSString*)userId jwt:(NSString*)jwt completionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))handler;

/**
 *  @abstract Logs out the current user.
 *
 *  @discussion Calling this method while already in anonymous state has no effect.
 *
 *  You may not call logout while the conversation screen is shown. Doing so will result in a no-op.
 */
+(void)logoutWithCompletionHandler:(nullable void(^)( NSError * _Nullable error, NSDictionary * _Nullable userInfo))completionHandler;

/**
 *  @abstract Force-start a conversation for the current user
 *
 *  @discussion Creates a user and conversation on the server, allowing the business to reach out proactively to the user via the public API.
 *
 *  It is strongly recommended to only call this method in the case where a message is likely to be sent.
 *
 *  This method is called automatically when starting a conversation via the -sendMessage: or -sendImage:withProgress:completion: methods, or when a user sends a message via the conversation view controller.
 *
 *  If a conversation already exists for the current user, this call is a no-op.
 */
+(void)startConversationWithCompletionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))completionHandler;

/**
 *  @abstract Toggles whether the input bar is displayed on the conversation view.
 *
 *  @discussion For some use cases, it can be useful to remove the ability for the user to craft their own messages. For example, if your conversation flow relies solely on postback buttons or quick replies, you may not want to allow the user to send anything other than the presented options.
 *
 *  Passing NO to this method will hide the input bar entirely, including the media button and the text area, thus preventing the user from sending messages themselves.
 *
 *  This method may be called at any time, even when the conversation view is currently displayed.
 *
 *  State is persisted across view controller launches.
 */
+(void)setConversationInputDisplayed:(BOOL)displayed;

/**
 *  @abstract Set the push notification token for this device.
 *
 *  @discussion This method is called automatically if MBCSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see MBCSettings
 */
+(void)setPushToken:(NSData*)token;

/**
 *  @abstract Handle an incoming push notification.
 *
 *  @discussion Call this method in your -application:didReceiveRemoteNotification: or -application:didReceiveRemoteNotification:fetchCompletionHandler: callback, passing the userInfo dictionary.
 *
 *  If the push notification did not originate from MindBehind, this is a no-op.
 *
 *  This method is called automatically if MBCSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see MBCSettings
 */
+(void)handlePushNotification:(NSDictionary*)userInfo;

/**
 *  @abstract An object conforming to UNUserNotificationCenterDelegate protocol, used to handle notifications on iOS 10 and above.
 *
 *  @discussion Implements both methods of UNUserNotificationCenterDelegate.
 *
 *  By default this object will automatically be set as the UNUserNotificationCenter delegate at init time. MindBehind will maintain a reference to your app's existing delegate (if applicable), and automatically forward any calls for notifications that did not originate from MindBehind.
 *
 *  To disable automatic overriding, you must set MBCSettings.enableUserNotificationCenterDelegateOverride to NO before calling +initWithSettings:completionHandler:. If you choose to do so, you must manually forward any relevant calls from your own delegate object. To check the origin of a notification, see the documentation for MBCPushNotificationIdentifier. For example:
 *
 *  -(void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler
 *  {
 *    if(notification.request.content.userInfo[MBCPushNotificationIdentifier] != nil){
 *      [[MindBehind userNotificationCenterDelegate] userNotificationCenter:center willPresentNotification:notification withCompletionHandler:completionHandler];
 *      return;
 *    }
 *  }
 *
 *  -(void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler
 *  {
 *    if(response.notification.request.content.userInfo[MBCPushNotificationIdentifier] != nil){
 *      [[MindBehind userNotificationCenterDelegate] userNotificationCenter:center didReceiveNotificationResponse:response withCompletionHandler:completionHandler];
 *      return;
 *    }
 *  }
 *
 *  @see MBCSettings
 *
 *  @return An object conforming to UNUserNotificationCenterDelegate protocol, or nil if +initWithSettings:completionHandler: hasn't been called yet.
 */
+(nullable id<UNUserNotificationCenterDelegate>)userNotificationCenterDelegate;

/**
 *  @abstract Handle the user input from a reply type notification action.
 *
 *  @discussion Call this method in your -application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler:, passing the action identifier, userInfo dictionary, responseInfo dictionary, and completionHandler callback.
 *
 *  This method will post a message on behalf of the user, with the contents of their inline reply. When the message upload completes (either in success or failure), the completion handler will be called.
 *
 *  If the action identifier does not match MBCUserNotificationReplyActionIdentifier, the completion handler will be called immediately and the notification will be ignored.
 *
 *  This method is called automatically if MBCSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see MBCSettings
 */
+(void)handleUserNotificationActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)(void))completionHandler;

/**
 *  @abstract Handle the user input from a reply type notification action.
 *
 *  @discussion Call this method in your -application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler:, passing the action identifier, responseInfo dictionary, and completionHandler callback.
 *
 *  This method will post a message on behalf of the user, with the contents of their inline reply. When the message upload completes (either in success or failure), the completion handler will be called.
 *
 *  If the action identifier does not match MBCUserNotificationReplyActionIdentifier, the completion handler will be called immediately and the notification will be ignored.
 *
 *  This method is called automatically if MBCSettings.enableAppDelegateSwizzling is set to YES.
 *
 *  @see MBCSettings
 *  @deprecated use +handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler: instead.
 */
+(void)handleUserNotificationActionWithIdentifier:(NSString *)identifier withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)(void))completionHandler;

/**
 *  @abstract A set of categories used for handling and displaying MindBehind user notification actions.
 *
 *  @discussion On iOS 8, returns an empty set.
 *  On iOS 9, returns a set of UIUserNotificationCategory objects, to be used with `UIUserNotificationSettings` +settingsForTypes:categories:
 *  On iOS 10, returns a set of UNNotificationCategory objects, to be used with `UNUserNotificationCenter` -setNotificationCategories:
 *
 *  Categories are registered automatically if MBCSettings.requestPushPermissionOnFirstMessage is set to YES. If automatic registration is disabled, you must make sure to include the MindBehind categories in your calls to the above mentioned methods.
 *
 *  @see MBCSettings
 */
+(NSSet*)userNotificationCategories;

/**
 *  @abstract Loads a conversation by its ID and sets it as the active conversation for the current session.
 *
 *  @discussion When called, subscribes the current device for push notifications on the passed conversationId, and sets the SDK to send and receive messages for that conversation going forward. Does not unsubscribe for notification on previously loaded conversations.
 *
 *  If the conversation is already set to the passed ID, this call is a no-op.
 */
+(void)loadConversation:(NSString*)conversationId completionHandler:(nullable void(^)(NSError * _Nullable error, NSDictionary * _Nullable userInfo))completionHandler;

/**
 *
 * @abstract Loads a list of conversations
 *
 * @discussion when called, returns an array of Conversation objects from storage
 *
 */
+ (void)getConversations:(void (^)(NSError  *_Nullable, NSArray  *_Nullable))completionHandler;

/**
 *
 * @abstract Updating the conversation delegate
 *
 *  @discussion when called, a new delegate is set
 */
+ (void)updateConversationDelegate:(id<MBCConversationDelegate>)delegate;

@end
NS_ASSUME_NONNULL_END
