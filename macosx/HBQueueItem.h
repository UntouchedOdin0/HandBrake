//
//  HBQueueItem.h
//  HandBrake
//
//  Created by Damiano Galassi on 07/02/2019.
//

#import <Foundation/Foundation.h>
#import "HBDistributedArray.h"

@import HandBrakeKit;

NS_ASSUME_NONNULL_BEGIN

/**
 *  A flag to indicate the item's state
 */
typedef NS_ENUM(NSUInteger, HBQueueItemState){
    HBQueueItemStateReady,
    HBQueueItemStateWorking,
    HBQueueItemStateCompleted,
    HBQueueItemStateCanceled,
    HBQueueItemStateFailed
};

@interface HBQueueItem : NSObject<NSSecureCoding, HBUniqueObject>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithJob:(HBJob *)job;

/// Current state of the job.
@property (nonatomic, readwrite) HBQueueItemState state;

/// The file URL of the source.
@property (nonatomic, readonly) NSURL *fileURL;

/// The file URL at which the new file will be created.
@property (nonatomic, readwrite, copy, nullable) NSURL *outputURL;

/// The name of the new file that will be created.
@property (nonatomic, readwrite, copy, nullable) NSString *outputFileName;

/// The file URL at which the new file will be created.
@property (nonatomic, readwrite, copy, nullable) NSURL *completeOutputURL;

@property (nonatomic, readonly) NSAttributedString *attributedTitleDescription;
@property (nonatomic, readonly) NSAttributedString *attributedDescription;

@property (nonatomic, readwrite) BOOL expanded;

@property (nonatomic, readonly) HBJob *job;

@end

NS_ASSUME_NONNULL_END
