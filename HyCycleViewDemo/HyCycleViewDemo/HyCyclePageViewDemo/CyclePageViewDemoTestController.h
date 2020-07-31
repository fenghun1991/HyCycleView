//
//  CyclePageViewDemoTestController.h
//  HyCycleView
//  https://github.com/hydreamit/HyCycleView
//
//  Created by Hy on 2016/5/20.
//  Copyright © 2016年 Hy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HyCyclePageView.h"

NS_ASSUME_NONNULL_BEGIN

@interface CyclePageViewDemoTestController : UITableViewController<HyCyclePageViewProviderProtocol>

@property (nonatomic,copy) void(^scrollViewDidEndDragging)(UIScrollView *scrollView);


@end

NS_ASSUME_NONNULL_END
