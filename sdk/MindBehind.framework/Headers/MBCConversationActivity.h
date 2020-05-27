//
//  MBCConversationActivity.h
//  MindBehind
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @abstract An activity type indicating that a participant of the converation started typing a response
 */
extern NSString *const MBCConversationActivityTypeTypingStart;

/**
 *  @abstract An activity type indicating that a participant of the converation stopped typing a response
 */
extern NSString *const MBCConversationActivityTypeTypingStop;

/**
 *  @abstract An activity type indicating that a participant of the converation recently read the user message
 *
 *  This event type is triggered for the current user when the conversation is read on a different device. 
 */
extern NSString *const MBCConversationActivityTypeConversationRead;

/**
 *  @abstract An activity type indicating that the current user was added to a conversation
 */
extern NSString *const MBCConversationActivityTypeConversationAdded;

/**
 *  @abstract An activity type indicating that the current user was removed from a conversation
 */
extern NSString *const MBCConversationActivityTypeConversationRemoved;

/**
 *  @abstract An activity type indicating that another user was added to a conversation that the current user is part of
 */
extern NSString *const MBCConversationActivityTypeParticipantAdded;

/**
 *  @abstract An activity type indicating that another user was removed from a conversation that the current user is part of
 */
extern NSString *const MBCConversationActivityTypeParticipantRemoved;

/**
 *  @abstract A key whose value is an NSString representing the appMaker name.
 *
 *  @discussion This key is used in the MBCConversationActivity data object.
 */
extern NSString *const MBCConversationActivityDataNameKey;

/**
 *  @abstract A key whose value is an NSString representing the URL of the appMaker avatar.
 *
 *  @discussion This key is used in the MBCConversationActivity data object.
 */
extern NSString *const MBCConversationActivityDataAvatarUrlKey;

@interface MBCConversationActivity : NSObject

/**
 *  @abstract the role of who is performing the typing activity
 */
@property(readonly, nullable) NSString *role;

/**
 *  @abstract the type of activity that is being triggered. Could be either
 *   - MBCConversationActivityTypeTypingStart
 *   - MBCConversationActivityTypeTypingStop
 *   - MBCConversationActivityTypeConversationRead
 *   - MBCConversationActivityTypeConversationAdded
 *   - MBCConversationActivityTypeConversationRemoved
 *   - MBCConversationActivityTypeParticipantAdded
 *   - MBCConversationActivityTypeParticipantRemoved
 */
@property(readonly) NSString *type;

/**
 *  @abstract additional data for this activity. Posible values are the appMaker's 'name' and/or 'avatarUrl'
 */
@property(readonly, nullable) NSDictionary *data;

/**
 *  @abstract conversationId for activity. Can be nil
 */
@property(readonly, nullable) NSString *conversationId;

/**
 *  @abstract date when the appMaker last read user messages for activities of type MBCConversationActivityTypeConversationRead
 */
@property(readonly, nullable) NSDate *appMakerLastRead;

/**
 * @abstract The appUserId if available, null otherwise
 *
 * available for MBCConversationActivityTypeParticipantAdded, MBCConversationActivityTypeParticipantRemoved
 */
@property(readonly, nullable) NSString *appUserId;

@end
NS_ASSUME_NONNULL_END
