//
//  IFTweetLabel.h
//  TwitterrificTouch
//
//  Created by Craig Hockenberry on 4/2/08.
//  Copyright 2008 The Iconfactory. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *IFTweetLabelURLNotification;

// NOTE: Yeah, it would make more sense to subclass UILabel to do this. But all the
// the UIButtons that got placed on top of the UILabel were not tappable. No amount of
// tinkering with userInteractionEnabled and the responder chain could be found to
// work around this issue.
//
// Instead, a normal view is used and an UILabel methods are supported through forward
// invocation.

@class IFTweetRegExpHelper;
@interface IFTweetLabel : UIView 
{
    UIFont *linkFont;
    
	UIColor *normalColor;
	UIColor *highlightColor;

	UIImage *normalImage;
	UIImage *highlightImage;
    
	UILabel *label;
	
	BOOL linksEnabled;
    
    IFTweetRegExpHelper *regExpHelper;    
}
@property (nonatomic, retain) UIFont *linkFont;

@property (nonatomic, retain) UIColor *normalColor;
@property (nonatomic, retain) UIColor *highlightColor;

@property (nonatomic, retain) UIImage *normalImage;
@property (nonatomic, retain) UIImage *highlightImage;

@property (nonatomic, retain) UILabel *label;

@property (nonatomic, assign) BOOL linksEnabled;

@property (nonatomic, retain) IFTweetRegExpHelper *regExpHelper;

- (void)setBackgroundColor:(UIColor *)backgroundColor;
- (void)setFrame:(CGRect)frame;

// Create your own links.
- (void)addLink:(NSString*)link;
- (void)addLinks:(NSArray*)links;
- (void)clearLinks;

@end


@interface IFTweetLabel (ForwardInvocation)

@property(nonatomic, copy) NSString *text;
@property(nonatomic) NSInteger numberOfLines;
@property(nonatomic, retain) UIColor *textColor;
@property(nonatomic, retain) UIFont *font;

@end

@interface IFTweetRegExpHelper : NSObject
{
    NSMutableArray *expressions;
}

@property (nonatomic, retain) NSMutableArray *expressions;

// Create your own links.
- (void)addLink:(NSString*)link;
- (void)addLinks:(NSArray*)links;
- (void)clearLinks;

@end
