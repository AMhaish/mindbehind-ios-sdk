//
//  MBCMessageAction.h
//  MindBehind
//

#import <Foundation/Foundation.h>

/**
 *  @abstract Type for a link action.
 */
extern NSString* _Nonnull const MBCMessageActionTypeLink;

/**
 *  @abstract Type for a webview action.
 */
extern NSString* _Nonnull const MBCMessageActionTypeWebview;

/**
 *  @abstract Type for a buy action.
 */
extern NSString* _Nonnull const MBCMessageActionTypeBuy;

/**
 *  @abstract Type for a postback action.
 */
extern NSString* _Nonnull const MBCMessageActionTypePostback;

/**
 *  @abstract Type for a reply action
 */
extern NSString* _Nonnull const MBCMessageActionTypeReply;

/**
 *  @abstract Type for a location request
 */
extern NSString* _Nonnull const MBCMessageActionTypeLocationRequest;

/**
 *  @abstract Offered state for a buy message. The user has not yet completed the transaction.
 */
extern NSString* _Nonnull const MBCMessageActionStateOffered;

/**
 *  @abstract Paid state for a buy message. The user has completed the transaction and payment was successful.
 */
extern NSString* _Nonnull const MBCMessageActionStatePaid;

/**
 *  @abstract A full-sized webview
 */
extern NSString* _Nonnull const MBCMessageActionWebviewSizeFull;

/**
 *  @abstract A tall-sized webview
 */
extern NSString* _Nonnull const MBCMessageActionWebviewSizeTall;

/**
 *  @abstract A compact-sized webview
 */
extern NSString* _Nonnull const MBCMessageActionWebviewSizeCompact;

/**
 *  @abstract An action associated to a particular MBCMessage.
 *
 *  Actions are rendered as buttons in the MindBehind conversation screen, and may be of type `MBCMessageActionTypeLink`, `MBCMessageActionTypeBuy` or `MBCMessageActionTypePostback`.
 *
 *  @see MBCMessage
 */
@interface MBCMessageAction : NSObject

/**
 *  @abstract The unique identifier representing the action.
 */
@property(readonly, nullable) NSString* actionId;

/**
 *  @abstract The type of action.
 *
 *  @discussion Valid types include `MBCMessageActionTypeLink` for regular actions, and `MBCMessageActionTypeBuy` for buy actions.
 */
@property(nullable) NSString* type;

/**
 *  @abstract The text to display as a descriptor for the action.
 *
 *  @discussion May not be nil.
 */
@property(nullable) NSString* text;

/**
 *  @abstract The URI to navigate to if the user interacts with the action.
 *
 *  @discussion May not be nil if message is of type `MBCMessageActionTypeLink` or `MBCMessageActionTypeWebview`
 */
@property(nullable) NSURL* uri;

/**
 *  @abstract Fallback URI to use for action types not supported by the SDK. May be nil.
 */
@property(nullable) NSURL* fallback;

/**
 *  @abstract The size of a webview
 *
 *  @discussion May not be nil if message is of type `MBCMessageActionTypeWebview`
 */
@property(nullable, copy) NSString* size;

/**
 *  @abstract Boolean value indicating whether this action is the default action for an MBCMessageItem
 *
 *  @discussion Default value is `NO`
 *
 *  @see MBCMessageItem
 */
@property(readonly) BOOL isDefault;

/**
 *  @abstract Metadata associated with the action.
 *
 *  @discussion A flat dictionary of metadata set through the REST API. May be nil.
 */
@property(nullable) NSDictionary* metadata;

/**
 *  @abstract Icon to display with a reply
 *
 *  @discussion An icon to render next to the reply option
 */
@property(nullable) NSString* iconUrl;

/**
 *  @abstract The payload of actions with type MBCMessageActionTypeReply or MBCMessageActionTypePostback
 *
 *  @discussion The payload of actions with type MBCMessageActionTypeReply or MBCMessageActionTypePostback, if applicable. May be nil
 */
@property(nullable) NSString* payload;

#pragma mark - Buy actions

/**
 *  @abstract The purchase state of the action
 *
 *  @discussion This property is only non-nil for actions of type `MBCMessageActionTypeBuy`. Valid states include `MBCMessageActionStateOffered` and `MBCMessageActionStatePaid`.
 */
@property(nullable) NSString* state;

/**
 *  @abstract The amount of money to charge for the action.
 *
 *  @discussion This property is only valid for actions of type `MBCMessageActionTypeBuy`. For USD, this value is in cents.
 */
@property long amount;

/**
 *  @abstract The currency in which the `amount` is expressed.
 *
 *  @discussion This property is only valid for actions of type `MBCMessageActionTypeBuy`.
 */
@property(nullable) NSString* currency;

@end
