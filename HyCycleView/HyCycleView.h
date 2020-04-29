//
//  HyCycleView.h
//  HyCycleView
//  https://github.com/hydreamit/HyCycleView
//
//  Created by Hy on 16/5/3.
//  Copyright © 2016年 Hy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+HyFrame.h"

/// scroll style
typedef NS_ENUM(NSUInteger, HyCycleViewScrollStyle) {
    /// need hand scroll
    HyCycleViewScrollStatic,
    /// auto scroll
    HyCycleViewScrollAuto
};

/// load style
typedef NS_ENUM(NSUInteger, HyCycleViewScrollLoadStyle) {
    /// view/controller view will appear load
    HyCycleViewScrollLoadStyleWillAppear,
    ///  view/controller view did appear load
    HyCycleViewScrollLoadStyleDidAppear
};

///scroll direction
typedef NS_ENUM(NSUInteger, HyCycleViewScrollDirection) {
    /// scroll to left
    HyCycleViewScrollLeft,
    /// scroll to right
    HyCycleViewScrollRight,
    /// scroll to top
    HyCycleViewScrollTop,
    /// scroll to bottom
    HyCycleViewScrollBottom
};


@class HyCycleView;
@interface HyCycleViewConfigure : NSObject

/// currentPage (当前页面)
@property (nonatomic,assign,readonly) NSInteger currentPage;
@property (nonatomic,weak,readonly) HyCycleView *cycleView;


/// cycle loop default yes (是否为无限循环轮播 默认为YES)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^isCycleLoop)(BOOL);
/// total Pages (总页数)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^totalPage)(NSInteger);
/// start page (开始页)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^startPage)(NSInteger);
/// timeInterval default 2.0 s (自动轮播时间间隔 默认2秒)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^timeInterval)(NSTimeInterval);

/// auto or static scroll style (轮播方式：自动/手动, 默认是自动)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^scrollStyle)(HyCycleViewScrollStyle);
/// cycle view load style (轮播View/Controller加载方式: 滑动出现立即加载/滑动到整个页面再加载)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^loadStyle)(HyCycleViewScrollLoadStyle);
/// scroll direction (轮播方向:左、右、上、下)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^scrollDirection)(HyCycleViewScrollDirection);


/// cycle views or controllers of class (轮播传入的是Class：view class 或者 controller class)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^cycleClasses)(NSArray<Class> *);
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^cycleClass)(Class(^)(HyCycleView *cycleView, NSInteger index));
/// cycle views or controllers (轮播传入的是实例对象：view 或者 controller)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^cycleInstances)(NSArray *);
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^cycleInstance)(id(^)(HyCycleView *cycleView, NSInteger index));


/// one cycle will appear callback (当轮播view/controllerView出现的回调)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^viewWillAppear)(void(^)(HyCycleView *cycleView, id instance, NSInteger index, BOOL isFirstLoad));
/// totalPage and currentPage change (总页/当前页发生改变的回调)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^currentPageChange)(void(^)(HyCycleView *cycleView, NSInteger indexs, NSInteger index));
/// totalPage and roundingPage change (总页/当前页(四舍五入)发生改变的回调)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^roundingPageChange)(void(^)(HyCycleView *cycleView, NSInteger indexs, NSInteger roundingIndex));


/// scroll progress (滑动进度的回调)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^scrollProgress)(void(^)(HyCycleView *cycleView, NSInteger fromIndex, NSInteger toIndex, CGFloat progress));
/// scroll state (滑动状态)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^scrollState)(void(^)(HyCycleView *cycleView, BOOL isStart));


/// click cycleView action (点击某个轮播view的回调)
@property (nonatomic,copy,readonly) HyCycleViewConfigure *(^clickAction)(void(^)(HyCycleView *cycleView, NSInteger index));


@end





@interface HyCycleView : UIView

/**
 create cycleView
 
 @param frame frame
 @param configureBlock config the params
 @return HyCycleView
 */
+ (instancetype)cycleViewWithFrame:(CGRect)frame
                    configureBlock:(void (^)(HyCycleViewConfigure *configure))configureBlock;


/// configure
@property (nonatomic, strong, readonly) HyCycleViewConfigure *configure;



/**
 scroll to next page
 
 @param animated animated
 */
- (void)scrollToNextPageWithAnimated:(BOOL)animated;


/**
 scroll to last page
 
 @param animated animated
 */
- (void)scrollToLastPageWithAnimated:(BOOL)animated;


/**
 scroll to the page
 
 @param page page
 @param animated animated
 */
- (void)scrollToPage:(NSInteger)page animated:(BOOL)animated;


/**
 reload initialize configure block
 */
- (void)reloadConfigureBlock;


/**
 changed configure with reload
 */
- (void)reloadConfigureChange;


@end

