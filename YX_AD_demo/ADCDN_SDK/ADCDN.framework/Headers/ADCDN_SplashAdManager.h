//
//  ADCDN_SplashAdManager.h
//  ADCDN
//
//  Created by 彭双塔 on 2019/9/27.
//  Copyright © 2019 pst. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class ADCDN_SplashAdManager;

@protocol ADCDN_SplashAdManagerDelegate <NSObject>
@optional
/**
 *  开屏广告成功展示
 */
- (void)ADCDN_SplashAdSuccessPresentScreen:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告展示失败
 */
- (void)ADCDN_SplashAdFailToPresent:(ADCDN_SplashAdManager *_Nullable)splashAd withError:(NSError *_Nullable)error;
/**
 *  开屏广告曝光回调
 */
- (void)ADCDN_SplashAdExposured:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告点击回调
 */
- (void)ADCDN_SplashAdClicked:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告将要关闭回调
 */
- (void)ADCDN_SplashAdWillClosed:(ADCDN_SplashAdManager *_Nullable)splashAd;
/**
 *  开屏广告关闭回调
 */
- (void)ADCDN_SplashAdClosed:(ADCDN_SplashAdManager *_Nullable)splashAd;
@end


@interface ADCDN_SplashAdManager : NSObject

@property (nonatomic, strong)UIWindow * _Nullable window;
@property (nonatomic, assign)CGRect wFrame;
/**
*  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View
*  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
*       请注意1.bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。2.Splash广告只支持竖屏
* bottomView 自定义底部View，可以在此View中设置应用Logo
*/
@property (nonatomic, strong)UIView * _Nullable bottomView;

@property (nonatomic, weak) id <ADCDN_SplashAdManagerDelegate> _Nullable delegate;
/**
 *  提供单例类方法
 */
+(instancetype _Nullable)shareManager;
/**
 *  加载开屏广告
 */
-(void)loadSplashAd;
@end
