//
//  HySegmentView.h
//  HyCycleView
//  https://github.com/hydreamit/HyCycleView
//
//  Created by Hy on 2016/5/22.
//  Copyright © 2016年 Hy. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, HySegmentViewItemPosition) {
    HySegmentViewItemPositionLeft,
    HySegmentViewItemPositionCenter,
    HySegmentViewItemPositionRight
};

@class HySegmentView;
@interface HySegmentViewConfigure : NSObject

/// current index
@property (nonatomic,assign,readonly) NSInteger currentIndex;

/// item margin default average (标签间距 默认是平均分配)
- (HySegmentViewConfigure *(^)(CGFloat))itemMargin;
/// start index default 0 (开始选中的标签数)
- (HySegmentViewConfigure *(^)(NSInteger))startIndex;
/// number of items （标签总数)
- (HySegmentViewConfigure *(^)(NSInteger))numberOfItems;

/// click item at index callback
- (HySegmentViewConfigure *(^)(void (^)(NSInteger, // click index
                                        BOOL))     // is repeat click
                                        )clickItemAtIndex;

/// view for item at index
- (HySegmentViewConfigure *(^)(UIView *(^)(UIView *,                      // current view
                                           NSInteger,                    // index
                                           CGFloat,                     // progress
                                           HySegmentViewItemPosition,  // position
                                           NSArray<UIView *> *))      // animationViews
                                           )viewForItemAtIndex;

/// animationViews
- (HySegmentViewConfigure *(^)(NSArray<UIView *> *(^)(NSArray<UIView *> *,     // current animationViews
                                                      UICollectionViewCell *, // from cell
                                                      UICollectionViewCell *,// to cell
                                                      NSInteger,            // from index
                                                      NSInteger,           // to index
                                                      CGFloat))           // progress
                                                      )animationViews;

@end

@interface HySegmentView : UIView


/**
 create HySegmentView

 @param frame frame
 @param configureBlock config the params
 @return HySegmentView
 */
+ (instancetype)segmentViewWithFrame:(CGRect)frame
                      configureBlock:(void (^)(HySegmentViewConfigure *configure))configureBlock;



/**
 click item at index

 @param index clicking index
 */
- (void)clickItemAtIndex:(NSInteger)index;



/**
 click item with progress

 @param fromIndex fromIndex
 @param toIndex toIndex
 @param progress progress
 */
- (void)clickItemFromIndex:(NSInteger)fromIndex
                   toIndex:(NSInteger)toIndex
                  progress:(CGFloat)progress;

@end


