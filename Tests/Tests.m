//
//  Tests.m
//  Tests
//
//  Created by Aleksander Slater on 06/05/2013.
//
//

#import "Tests.h"
#import "IFTweetLabel.h"
#import "RegexKitLite.h"
#import "RKLMatchEnumerator.h"

@implementation Tests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

/*
- (void)testExample
{
    STFail(@"Unit tests are not implemented yet in Tests");
}*/

- (void)testRegExp
{
    IFTweetRegExpHelper *helper = [[IFTweetRegExpHelper alloc] init];
    
    NSString *text = @"This is a test to see if Test Link will be detected.";
    NSString *link = @"Test Link";
    
    [helper clearLinks];
    [helper addLink:link];
    
    BOOL wasMatched = NO;
    for (NSString *expression in helper.expressions)
	{
		NSString *match;
		NSEnumerator *enumerator = [text matchEnumeratorWithRegex:expression];
        
        while (match = [enumerator nextObject])
		{
			if ([match hasPrefix:link])
			{
				wasMatched = YES;
			}
		}
    }
    
    if (!wasMatched) STFail(@"Failed to match link in text");
    
    text = @"Bob Jones and James Bond, CIC, CLTC are now Contacts.";
    link = @"James Bond, CIC, CLTC";
    
    [helper clearLinks];
    [helper addLink:link];
    
    wasMatched = NO;
    for (NSString *expression in helper.expressions)
	{
		NSString *match;
		NSEnumerator *enumerator = [text matchEnumeratorWithRegex:expression];
        
        while (match = [enumerator nextObject])
		{
			if ([match hasPrefix:link])
			{
				wasMatched = YES;
			}
		}
    }
    
    if (!wasMatched) STFail(@"Failed to match link2 in text");
    
    [helper release];
}

@end
