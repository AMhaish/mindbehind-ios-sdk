//
//  MBCMessage.h
//  MindBehind
//

#import <UIKit/UIKit.h>
#import "MBCCoordinates.h"
#import "MBCDisplaySettings.h"

/**
 *  @abstract Notification that is fired when a message fails to upload.
 */
extern NSString* _Nonnull const MBCMessageUploadFailedNotification;

/**
 *  @abstract Notification that is fired when a message uploads successfully.
 */
extern NSString* _Nonnull const MBCMessageUploadCompletedNotification;

/**
 *  @abstract A type of message that contains an image, text, and/or action buttons
 */
extern NSString* _Nonnull const MBCMessageTypeImage;

/**
 *  @abstract A type of message that contains text and/or action buttons
 */
extern NSString* _Nonnull const MBCMessageTypeText;

/**
 *  @abstract A type of message that contains a location
 */
extern NSString* _Nonnull const MBCMessageTypeLocation;

/**
 *  @abstract A type of message that contains a file and/or text
 */
extern NSString* _Nonnull const MBCMessageTypeFile;

/**
 *  @abstract A type of message that contains a horizontally scrollable set of items
 */
extern NSString* _Nonnull const MBCMessageTypeCarousel;

/**
 *  @abstract A type of message that contains a vertically scrollable set of items
 */
extern NSString* _Nonnull const MBCMessageTypeList;

/**
 *  @discussion Upload status of an MBCMessage.
 *
 *  @see MBCMessage
 */
typedef NS_ENUM(NSInteger, MBCMessageUploadStatus) {
    /**
     *  A user message that has not yet finished uploading.
     */
    MBCMessageUploadStatusUnsent,
    /**
     *  A user message that failed to upload.
     */
    MBCMessageUploadStatusFailed,
    /**
     *  A user message that was successfully uploaded.
     */
    MBCMessageUploadStatusSent,
    /**
     *  A message that did not originate from the current user.
     */
    MBCMessageUploadStatusNotUserMessage
};

@interface MBCMessage : NSObject <NSSecureCoding>

/**
 *  @abstract Create a message with the given text. The message will be owned by the current user.
 */
-(nonnull instancetype)initWithText:(nonnull NSString*)text;

/**
 *  @abstract Create a message with the given text, payload, and metadata. The message will be owned by the current user
 */
-(nonnull instancetype)initWithText:(nonnull NSString *)text payload:(nullable NSString *)payload metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract Create a message with the given coordinates, payload, and metadata. The message will be owned by the current user
 */
-(nonnull instancetype)initWithCoordinates:(nonnull MBCCoordinates *)coordinates payload:(nullable NSString *)payload metadata:(nullable NSDictionary *)metadata;

/**
 *  @abstract The unique identifier of the message. May be nil if a unique identifier has not been generated for this message
 */
@property(readonly, nullable) NSString* messageId;

/**
 *  @abstract The text content of the message. May be nil if mediaUrl or actions are provided
 */
@property(nullable) NSString* text;

/**
 *  @abstract The text fallback to display for message types not supported by the SDK. May be nil
 */
@property(nullable) NSString* textFallback;

/**
 *  @abstract The name of the author. This property may be nil if no name could be determined.
 */
@property(nullable) NSString* name;

/**
 *  @abstract The url for the author's avatar image. May be nil
 */
@property(nullable) NSString* avatarUrl;

/**
 *  @abstract The date and time the message was sent
 */
@property(nullable) NSDate *date;

/**
 *  @abstract Returns YES if the message originated from the user, or NO if the message comes from the app team.
 */
@property (nonatomic) BOOL isFromCurrentUser;

/**
 *  @abstract The upload status of the message.
 *
 *  @see MBCMessageStatus
 */
@property(readonly) MBCMessageUploadStatus uploadStatus;

/**
 *  @abstract An array of MBCMessageAction objects representing the actions associated with this message (if any)
 *
 *  @discussion This array may be nil or empty, so check the length of the array to know if a message has actions or not.
 *
 *  @see MBCMessageAction
 */
@property(readonly, nullable) NSArray* actions;

/**
 *  @abstract An array of MBCMessageItem objects representing the items associated with this message
 *
 *  @discussion Only messages of type `MBCMessageTypeCarousel` and `MBCMessageTypeList` contain items.
 *
 *  @see MBCMessageItem
 */
@property(readonly, nullable) NSArray* items;

/**
 *  @abstract The url to the media asset, if applicable. Returns nil if the message is not an image or file message.
 */
@property(nullable) NSString* mediaUrl;

/**
 *  @abstract The size of the media asset in bytes. May be nil.
 */
@property(nullable) NSNumber* mediaSize;

/**
 *  @abstract The type the message.
 *
 *  @discussion Valid types include MBCMessageTypeText, MBCMessageTypeImage, and MBCMessageTypeLocation
 */
@property(nullable) NSString* type;

/**
 *  @abstract Coordinates for a location for a message of type MBCMessageTypeLocation
 */
@property(readonly, nullable) MBCCoordinates *coordinates;

/**
 *  @abstract Settings to adjust the layout of a message of type MBCMessageTypeCarousel
 *
 *  @see MBCDisplaySettings
 */
@property(readonly, nullable) MBCDisplaySettings *displaySettings;

/**
 *  @abstract The role of the message.
 *
 *  @discussion Valid roles include `appUser`, `appMaker`, and `whisper`. Messages created with -initWithText: have role of `appUser`.
 */
@property(readonly, nullable) NSString* role;

/**
 *  @abstract Metadata associated with the message.
 *
 *  @discussion A flat dictionary of metadata set through the REST API. May be nil.
 */
@property(nullable) NSDictionary* metadata;

/**
 *  @abstract The payload of an action with type MBCMessageActionTypeReply
 *
 *  @discussion The payload of a MBCMessageActionTypeReply, if applicable. May be nil
 */
@property(nullable) NSString* payload;

@end
