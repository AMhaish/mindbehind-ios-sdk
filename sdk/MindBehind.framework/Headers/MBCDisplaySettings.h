//
//  MBCDisplaySettings.h
//  MindBehind
//

#import <Foundation/Foundation.h>

/**
 *  @abstract horizontal image aspect ratio
 */
extern NSString* _Nonnull const MBCImageAspectRatioHorizontal;

/**
 *  @abstract squared image aspect ratio
 */
extern NSString* _Nonnull const MBCImageAspectRatioSquare;

/**
 *  @abstract Settings to adjust a carousel layout
 */
@interface MBCDisplaySettings : NSObject

/*
 * @abstract Specifies how to display all carousel images
 *
 * @discussion Valid values are horizontal and square. May be nil
 */
@property (nullable, copy) NSString *imageAspectRatio;

@end
