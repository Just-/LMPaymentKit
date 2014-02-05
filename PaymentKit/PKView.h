//
//  PKPaymentField.h
//  PKPayment Example
//
//  Created by Alex MacCaw on 1/22/13.
//  Copyright (c) 2013 Stripe. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PKCard.h"
#import "PKCardNumber.h"
#import "PKCardExpiry.h"
#import "PKCardCVC.h"
#import "PKAddressZip.h"
#import "PKUSAddressZip.h"

@class PKView, PKTextField;

typedef enum {
    PKViewStateCardNumber,
	PKViewStateExpiry,
	PKViewStateCVC
} PKViewState;

typedef enum {
	PKViewImageStyleNormal,
  PKViewImageStyleOutline,
  PKViewImageStyleNone
} PKViewImageStyle;

@protocol PKViewDelegate <NSObject>
@optional
- (void)paymentView:(PKView *)paymentView withCard:(PKCard *)card isValid:(BOOL)valid;
- (void)paymentView:(PKView *)paymentView didChangeState:(PKViewState)state;
@end

@interface PKView : UIView

- (BOOL)isValid;

@property(nonatomic) UITextBorderStyle borderStyle;
@property(nonatomic) PKViewImageStyle imageStyle;
@property(nonatomic) UIFont *font;
@property(nonatomic) UIColor *textColor;
@property(nonatomic, copy) NSDictionary *defaultTextAttributes;

@property (nonatomic, readonly) UIView *opaqueOverGradientView;
@property (nonatomic, readonly) PKCardNumber *cardNumber;
@property (nonatomic, readonly) PKCardExpiry *cardExpiry;
@property (nonatomic, readonly) PKCardCVC *cardCVC;
@property (nonatomic, readonly) PKAddressZip *addressZip;

@property UIView *innerView;
@property UIView *clipView;
@property PKTextField *cardNumberField;
@property UITextField *cardLastFourField;
@property PKTextField *cardExpiryField;
@property PKTextField *cardCVCField;
@property UIImageView *placeholderView;
@property (weak) id <PKViewDelegate> delegate;
@property (readonly) PKCard *card;

@end
